isPalindrome :: String -> Bool
isPalindrome "" = False
isPalindrome s  = s == reverse s
-- reverse, это O(n), плюс (==), тоже O(n)