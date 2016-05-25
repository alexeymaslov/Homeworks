data Expression = X
                | Const Int
                | Expression :+: Expression
                | Expression :-: Expression
                | Expression :*: Expression
                | Expression :/: Expression
                | Expression :^: Int
                deriving (Show, Eq)
              
derive :: Expression -> Expression
derive X                 = Const 1
derive (Const n)         = Const 0
derive (expr1 :+: expr2) = (derive expr1) :+: (derive expr2)
derive (expr1 :-: expr2) = (derive expr1) :-: (derive expr2)
derive (expr1 :*: expr2) = ((derive expr1) :*: expr2) :+: (expr1 :*: (derive expr2))
derive (expr1 :/: expr2) = (((derive expr1) :*: expr2) :-: (expr1 :*: (derive expr2))) :/: (expr2 :*: expr2)
derive (expr1 :^: n)     = (Const n) :*: (expr1 :^: (n - 1)) :*: (derive expr1)

simplify :: Expression -> Expression
simplify (Const a :+: Const b) = Const (a + b)
simplify (Const a :-: Const b) = Const (a - b)
simplify (Const a :*: Const b) = Const (a * b)
simplify (Const a :/: Const b) = Const (a `div` b)
simplify (Const a :^: b)       = Const (a ^ b)

simplify (Const 0 :+: expr) = simplify expr
simplify (expr :+: Const 0) = simplify expr
simplify (Const 0 :-: expr) = simplify (Const (-1) :*: expr)
simplify (expr :-: Const 0) = simplify expr
simplify (Const 0 :*: expr) = Const 0
simplify (expr :*: Const 0) = Const 0
simplify (expr :*: Const 1) = simplify expr
simplify (Const 1 :*: expr) = simplify expr
simplify (expr :^: 0)       = Const 1
simplify (expr :^: 1)       = simplify expr
simplify (expr :/: Const 1) = simplify expr

simplify (expr1 :+: expr2) = (simplify expr1) :+: (simplify expr2)
simplify (expr1 :-: expr2) = (simplify expr1) :-: (simplify expr2)
simplify (expr1 :*: expr2) = (simplify expr1) :*: (simplify expr2)
simplify (expr1 :/: expr2) = (simplify expr1) :/: (simplify expr2)
simplify (expr1 :^: n)     = (simplify expr1) :^: n

simplify expr = expr

simplifyEquation :: Expression -> Expression
simplifyEquation expr | expr == simplify expr   = expr
                      | otherwise               = simplifyEquation (simplify expr)

main = print $ simplifyEquation $ derive ((X :^: 2) :-: (Const 2 :*: X) :+: Const 3)
             
             
         