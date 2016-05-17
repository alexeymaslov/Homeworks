import Data.List (maximumBy)
import Data.Function (on)

findIndexOfMaxPair :: [Integer] -> Integer
findIndexOfMaxPair list = fst (maximumBy (compare `on` snd) (reverse indexedSums))
    where
    indexedSums = [( (fst x) + 1, (snd x) + (snd y) ) | x <- indexedList, y <- indexedList, (fst y) - (fst x) == 2]
    indexedList = zip [1..] list