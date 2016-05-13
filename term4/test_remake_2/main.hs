getMatrix :: Int -> [[Int]]
getMatrix a = getMatrix_helper a 1 
    where
    getMatrix_helper :: Int -> Int -> [[Int]]
    getMatrix_helper a i | i <= a = (buildSuchList i 1 a) : (getMatrix_helper a (i + 1))
    getMatrix_helper a i | otherwise = []

-- Строит список вида [x, x,..., x, x + 1,..., max]
buildSuchList :: Int -> Int -> Int -> [Int]
buildSuchList x i max   | i < x = x:(buildSuchList x (i + 1) max)
                        | i <= max = i:(buildSuchList x (i + 1) max)
                        | otherwise = []