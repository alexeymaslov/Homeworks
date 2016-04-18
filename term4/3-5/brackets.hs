import Data.Maybe

checkBrackets :: String -> Bool
checkBrackets s = checkBrackets_helper s ""
    where
    checkBrackets_helper :: String -> String -> Bool
    checkBrackets_helper [] stack = null stack
    checkBrackets_helper (x:xs) stack 
        | not (elem x "[](){}")             = checkBrackets_helper xs stack
        | elem x "[({"                      = checkBrackets_helper xs ((getSameClosing x):stack)      --Добавляем соответствующую закрывающую скобку в стек
        | elem x "])}" && not (null stack)  = x == head stack && checkBrackets_helper xs (tail stack) --Проверяем, что скобка в стеке соответствует, и удаляем ее
        | otherwise                         = False
        where
        getSameClosing :: Char -> Char
        getSameClosing x = fromJust $ lookup x (zip "[{(" "]})")
    
