import Data.List

data Polynomial = Polynomial [Int]

add :: Polynomial -> Polynomial -> Polynomial
add p1@(Polynomial x) p2@(Polynomial y) | length x >= length y = Polynomial (zipWith (+) x (y ++ repeat 0))
                                        | otherwise            = add p2 p1

multiply :: Polynomial -> Polynomial -> Polynomial
multiply (Polynomial []) p2 = Polynomial []
multiply (Polynomial (x:xs)) p2@(Polynomial y) = add (multiplyBy x p2) (multiplyByX $ multiply (Polynomial xs) p2)

multiplyBy :: Int -> Polynomial -> Polynomial
multiplyBy c (Polynomial x) = Polynomial (map (c * ) x)

multiplyByX :: Polynomial -> Polynomial
multiplyByX (Polynomial x) = Polynomial (0 : x)

instance Show Polynomial where
    show p = showPolynomial p

showPolynomial :: Polynomial -> String
showPolynomial (Polynomial x) = intercalate " + " (reverse terms)
                                where
                                terms = map (\(c,n) -> show_helper c n) indexedListWithoutZero
                                
                                indexedList = zip x [0..]
                                indexedListWithoutZero = filter (\(c,_) -> c /= 0) indexedList
                                
                                showConst c | c == 1    = ""
                                            | otherwise = show c
                                            
                                showDegree n = case n of
                                                0 -> ""
                                                1 -> "x"
                                                k -> "x^" ++ show k
                                                
                                show_helper c n | c == 1 && n == 0 = show 1
                                                | otherwise        = intercalate " " $ filter (/="") [showConst c, showDegree n]