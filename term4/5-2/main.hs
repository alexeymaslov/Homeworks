--productList2 n = [x * y | x <- [1..n], y <- [1..n]]

productList :: Int -> [Int]
productList n = [1..n] >>= \x -> [1..n] >>= \y -> return (x * y)