myMerge :: (Ord a) => [a] -> [a] -> [a]
myMerge [] ys = ys
myMerge xs [] = xs
myMerge (allx@(x:xs)) (ally@(y:ys))
    | (x <= y) = x : myMerge xs ally
    | otherwise = y : myMerge allx ys
    
myList = l where
    l = (1:7:9:lm10p179)               --[1, 7, 9, 11..]
    lm10 = map ((*) 10) l              --[10, 70, 90, 110..]
    lm10p1 = map ((+) 1) lm10          --[11, 71, 91, 111..]
    lm10p7 = map ((+) 7) lm10          --[17, 77, 97, 117..]
    lm10p9 = map ((+) 9) lm10          --[19, 79, 99, 119..]
    lm10p17 = myMerge lm10p1 lm10p7    --[11, 17, 71, 77..]
    lm10p179 = myMerge lm10p17 lm10p9  --[11, 17, 19, 71..]