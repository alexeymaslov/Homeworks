--func x l = map (\y -> y*x) l

--func x l = map ((*) x) l

--func x = map ((*) x)

--func x = (map . (*)) x

func = map . (*)
