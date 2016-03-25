getPos :: Eq a => a -> [a] -> Int
getPos a l  | length l == lt     = -1
            | otherwise          = lt 
            where
            lt = length (takeWhile (/= a) l)
