createList :: Integer -> [Integer]
createList n = creation_helper n [] where
    creation_helper :: Integer -> [Integer] -> [Integer]
    creation_helper 0 a = a
    creation_helper n a = creation_helper (n - 1) ((2 ^ n) : a) 
