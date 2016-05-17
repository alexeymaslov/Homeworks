data Tree a = Empty | Node a (Tree a) (Tree a)
    deriving (Show)
  
foldTree :: (a -> b -> b -> b) -> b -> Tree a -> b
foldTree f z (Empty) = z
foldTree f z (Node a left right) = f a (foldTree f z left) (foldTree f z right)

filterTree :: (a -> Bool) -> Tree a -> Tree a
filterTree p Empty = Empty
filterTree p (Node a left right)
    | p a       = Node a (filterTree p left) (filterTree p right)
    | otherwise = pushRightmost (filterTree p left) (filterTree p right)
    where
    -- Делает из двух деревьев одно, помещая второе дерево в самое правое поддерево первого дерева
    pushRightmost :: Tree a -> Tree a -> Tree a
    pushRightmost Empty x = x
    pushRightmost (Node a left right) x = Node a left (pushRightmost right x)
    

