import Data.List
import Data.Map ((!), fromList, fromListWith, adjust, keys, Map)
import Control.Monad.State
import Control.Monad(when)

data Graph v = Graph [(Int, v)] [(Int, Int, Float)] deriving Show

dijkstra :: Graph v -> Int -> Map Int (Float, Maybe Int)
dijkstra (Graph vertices edges) start = (\(_,a,_) -> a) $ snd $ runState dijkstra_helper (build_helper edges)
    where
    build_helper :: [(Int, Int, Float)] -> (Map Int [(Int, Float)],Map Int (Float, Maybe Int),[Int])
    build_helper edges = (graph, dist, vert)
        where
        -- вершина <-> список инциндентных ей вершин с длинами ребер
        graph = fromListWith (++) $ edges >>= \(from,to,length)
         -> [(from,[(to,length)]), (to,[(from,length)])]
        -- вершина <-> путь до нее и возможно предыдущая вершина в пути (для нахождения потом кратчайшего пути)
        dist = fromList [(v, (if v == start then 0 else 1/0, Nothing)) | v <- keys graph]
        -- список еще непосещенных вершин
        vert = keys graph
    
    dijkstra_helper :: State (Map Int [(Int, Float)],Map Int (Float, Maybe Int),[Int]) ()
    dijkstra_helper = do
        noMoreVertices <- isListEmpty
        when (not noMoreVertices) $ do
            minIndex <- findMinimumVert
            adjustLengths minIndex
            removeObsoleteVert minIndex
            dijkstra_helper
        where
        isListEmpty :: State (Map Int [(Int, Float)],Map Int (Float, Maybe Int),[Int]) Bool
        isListEmpty = state $ \(graph,dist,vert) -> (null $ vert,(graph,dist,vert))
        
        findMinimumVert :: State (Map Int [(Int, Float)],Map Int (Float, Maybe Int),[Int]) Int
        findMinimumVert = state $ \(graph,dist,vert)
         -> (snd $ minimum $ [(fst . (dist!) $ x, x) | x <- vert],(graph,dist,vert))
        
        adjustLengths :: Int -> State (Map Int [(Int, Float)],Map Int (Float, Maybe Int),[Int]) ()
        adjustLengths i = state $ \(graph,dist,vert)
         -> ((),(graph, foldr (\(e,d) 
         -> adjust (min (fst (dist ! i) + d, Just i)) e) dist $ graph ! i, vert))
        
        removeObsoleteVert :: Int -> State (Map Int [(Int, Float)],Map Int (Float, Maybe Int),[Int]) ()
        removeObsoleteVert i = state $ \(graph,dist,vert) -> ((),(graph, dist, delete i vert))

shortestPath :: Int -> Int -> Map Int (Float, Maybe Int) -> [Int]
shortestPath from to dijkstraMap = reverse $ helper to
    where
    helper to = to : maybe [] helper (snd $ dijkstraMap ! to)
    
main :: IO ()    
main = do
    print $ shortestPath start to dijkstra_result == [1,2,3,4]
    where
    g = Graph [(1,'a'),(2,'b'),(3,'c'),(4,'d')] [(1,2,2),(2,3,4),(3,4,8),(1,4,20)]
    start = 1
    dijkstra_result = dijkstra g start
    to = 4
    