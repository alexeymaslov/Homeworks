checkUniqueList :: Eq a => [a] -> Bool
checkUniqueList [] = True
checkUniqueList (x:xs) = (checkUnique_helper x xs) && (checkUniqueList xs)
    where
    checkUnique_helper :: Eq a => a -> [a] -> Bool
    checkUnique_helper a [] = True
    checkUnique_helper a (x:xs) = (a /= x) && checkUnique_helper a xs