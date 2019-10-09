from collections import Counter

def frequecy_using_counter(arr):
	frequency = Counter(arr)
	return dict(frequency)

def frequency_using_dicts(arr):
	frequency = dict()
	for element in arr:
		try:
			frequency[element]+=1
		except KeyError:
			frequency[element] = 1

	return frequency

sequence = [1,2,3,4,5,7,8,9,2,3,5,9,7,2,1]
print(frequecy_using_counter(sequence))
print(frequency_using_dicts(sequence))