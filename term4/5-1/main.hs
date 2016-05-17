decompose :: Int -> [[Int]]
decompose 0 = [[]]
decompose n = [x : y | x <- [1..n], y <- decompose (n - x), (null y || x <= head y)] 