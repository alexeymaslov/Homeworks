getSumDividedByCos :: Floating a => [a] -> a
getSumDividedByCos l = getSumDividedByCos_helper l 0 1 where
    getSumDividedByCos_helper :: Floating a => [a] -> a -> a -> a
    getSumDividedByCos_helper [] s p = (s / p)
    getSumDividedByCos_helper (x:xs) s p = getSumDividedByCos_helper xs (s + x) (p * cos (x))