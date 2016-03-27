reverse_ :: [a] -> [a]
reverse_ l =  reverse_helper l [] where
    reverse_helper :: [a] -> [a] -> [a]
    reverse_helper [] a = a
    reverse_helper (x:xs) a = reverse_helper xs (x:a)