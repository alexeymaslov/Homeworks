primeNumbers :: [Integer]
primeNumbers = eratosphenAlgorithm [2..]

eratosphenAlgorithm :: [Integer] -> [Integer]
eratosphenAlgorithm (prime:xs) = prime : eratosphenAlgorithm (removeMultiple prime xs)

-- Убираем кратные простому
removeMultiple :: Integer -> [Integer] -> [Integer]
removeMultiple prime l = [x | x <- l, mod x prime /= 0]