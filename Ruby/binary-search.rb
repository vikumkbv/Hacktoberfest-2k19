def binary_search(n, arr)
  middle = arr[arr.length / 2]
  i = 0
  j = arr.length - 1

  while i < j
    if middle == n
      return true
    elsif middle < n
      i = middle
      middle = i + j / 2
    else
      j = middle
      middle = i + j / 2
    end
  end
  false
end 
