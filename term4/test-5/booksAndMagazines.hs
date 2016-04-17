data Pressed = Book String String Double | Magazine String Integer Integer Double

calculateCost :: [Pressed] -> Double
calculateCost [] = 0
calculateCost ( (Book name author cost) : xs) = cost + (calculateCost xs)
calculateCost ( (Magazine name year number cost) : xs) = cost + (calculateCost xs)