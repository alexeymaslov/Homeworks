data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Eq, Show)

add :: (Ord a) => a -> Tree a -> Tree a
add x Empty = Node x Empty Empty
add x node@(Node y l r) | x > y = Node y l (add x r)
                        | x < y = Node y (add x l) r
                        | otherwise = node
                    
height :: Tree a -> Int
height Empty = 0
height (Node x l r) = max (height l) (height r) + 1

size :: Tree a -> Int
size Empty = 0
size (Node x l r) = size l + size r + 1

exists :: (Ord a) => a -> Tree a -> Bool
exists x Empty = False
exists x (Node y l r)   | x > y = exists x r
                        | x < y = exists x l
                        | otherwise = True
                        
remove :: (Ord a) => a -> Tree a -> Tree a
remove x Empty = Empty
remove x (Node y l r)   | x > y = Node y l (remove x r)
                        | x < y = Node y (remove x l) r
                        | l == Empty = r
                        | r == Empty = l
                        | otherwise = Node (getMinValue r) l (remove (getMinValue r) r)
                            where
                            getMinValue :: Tree a -> a
                            getMinValue (Node x Empty r) = x
                            getMinValue (Node x l r) = getMinValue l

someTree = Node 6 (Node 2 Empty Empty) (Node 10 Empty (Node 16 Empty Empty))