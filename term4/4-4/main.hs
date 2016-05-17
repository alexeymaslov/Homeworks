main = doLoop []
   
doLoop :: [Int] -> IO ()   
doLoop list = do
    putStrLn "Enter command:\n0 - exit\n1 - add value\n2 - remove value\n3 - print list"
    input <- getLine
    case (head input) of
        '0' -> return ()
        '1' -> doAdd list
        '2' -> doRemove list
        '3' -> doPrint list
        otherwise -> doLoop list

doAdd :: [Int] -> IO ()
doAdd list = do
    putStrLn "Enter value:"
    input <- getLine
    doLoop (addValueToSorted (read input :: Int) list)

doRemove :: [Int] -> IO ()
doRemove list = do
    putStrLn "Enter value:"
    input <- getLine
    doLoop (removeValueFromSorted (read input :: Int) list)

doPrint :: [Int] -> IO ()
doPrint list = do
    putStrLn "List:"
    print list
    doLoop list
    
addValueToSorted  :: Ord a => a -> [a] -> [a]
addValueToSorted a [] = a:[]
addValueToSorted a (x:xs) 
    | a >= x        = x : (addValueToSorted a xs)
    | otherwise     = a:x:xs
    
removeValueFromSorted :: Ord a => a -> [a] -> [a]
removeValueFromSorted a [] = []
removeValueFromSorted a l@(x:xs)
    | a > x         = x : (removeValueFromSorted a xs)
    | a == x        = xs
    | otherwise     = l