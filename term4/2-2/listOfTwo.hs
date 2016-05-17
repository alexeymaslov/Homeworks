createList :: Int -> [Int]
createList n = map ((^) 2 ) (take n [1, 2..])