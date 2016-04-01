--let x = [1,2,100,4,5];

findIndexOfMaxPair :: [Integer] -> Integer
findIndexOfMaxPair [] = 0
findIndexOfMaxPair l = findIndexOfMaxPair_helper l 0 1 0
    where
    findIndexOfMaxPair_helper :: [Integer] -> Integer -> Integer -> Integer -> Integer
    findIndexOfMaxPair_helper (x:(xs@(y:ys))) sum i maxI | x + y > sum = findIndexOfMaxPair_helper xs (x + y) (i + 1) i
                                                         | otherwise = findIndexOfMaxPair_helper xs sum (i + 1) maxI
    findIndexOfMaxPair_helper (x:[]) sum i maxI = maxI