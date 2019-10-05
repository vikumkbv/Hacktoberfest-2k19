import Data.List (unfoldr)

fibonacci :: [Int]
fibonacci = unfoldr (\(a, b) -> Just (a, (b, a + b))) (0, 1)

