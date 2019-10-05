{- You'll need to provide it with a `count` value which will
   be equivalent to the number of elements of the fibonacci
   sequence to calculate.

   Example:
     fibonacci 15 == [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377 ]
-}
fibonacci : Int -> List Int
fibonacci c =
  let
    go count res =
      if count > 0 then
        case List.reverse res of
	  (x :: y :: rest) ->
	    go (count - 1) (res ++ [ x + y ])
	  _ ->
	    res
      else
        res
  in
  go (c - 2) [0, 1]

