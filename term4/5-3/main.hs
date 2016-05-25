import Control.Monad

getFirstLocalMax :: (Ord a) => [a] -> Maybe a
getFirstLocalMax l = foldl mplus Nothing (localMaxes l)

localMaxes :: (Ord a) => [a] -> [Maybe a]
localMaxes (x : l@(y : z : xs)) | x < y && y > z = (Just y) : (localMaxes l)
                                | otherwise      = Nothing : (localMaxes l)
localMaxes _ = []