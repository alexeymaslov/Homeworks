checkList1 :: [Int] -> Int
checkList1 l = foldr (\x y -> y + 1) 0 (filter even l)

checkList2 :: [Int] -> Int
checkList2 l = foldr (+) 0 (map (\x -> 1 - x `mod` 2) l)

checkList3 :: [Int] -> Int
checkList3 l = foldr (\x y -> y + (1 - x `mod` 2)) 0 l