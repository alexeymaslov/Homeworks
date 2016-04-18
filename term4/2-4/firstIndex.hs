-- Returns -1 if there is no such value in a list
getFirstIndex :: Integer -> [Integer] -> Integer
getFirstIndex n a = getFirstIndex_helper a 0 where
    getFirstIndex_helper :: [Integer] -> Integer -> Integer
    getFirstIndex_helper [] i = -1
    getFirstIndex_helper (x:xs) i | x == n    = i
                                  | otherwise = getFirstIndex_helper xs (i + 1)