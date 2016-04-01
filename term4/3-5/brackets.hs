checkBrackets :: String -> Bool
checkBrackets s = (checkBrackets_helper s 0) == 0
    where
    checkBrackets_helper :: String -> Int -> Int
    checkBrackets_helper _ (-1) = -1                                  --Случай, когда закрывающих скобок больше чем открывающих
    checkBrackets_helper [] i = i
    checkBrackets_helper (']':xs) i = checkBrackets_helper xs (i - 1)
    checkBrackets_helper ('[':xs) i = checkBrackets_helper xs (i + 1)