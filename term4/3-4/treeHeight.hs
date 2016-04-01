data Tree a = Empty | Node a (Tree a) (Tree a)

height :: Tree a -> Integer
height Empty = 0
height (Node value left right) = max (height left) (height right) + 1

minToLeaf :: Tree a -> Integer
minToLeaf Empty = -1
minToLeaf (Node value Empty Empty) = 0
minToLeaf (Node value Empty right) = minToLeaf right + 1
minToLeaf (Node value left Empty) = minToLeaf left + 1
minToLeaf (Node value left right) = min (minToLeaf left) (minToLeaf right) + 1