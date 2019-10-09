def selection_sort(list):	

	for i in range(len(list)-1):
		min = i
		for j in range(i+1,len(list)):
			if(list[j]<list[min]):
				min = j
		temp = list[i]
		list[i] = list[min]
		list[min] = temp

x = input().split()
list = []

for i in range(len(x)):
	list.append(int(x[i]))

selection_sort(list)

print(list)
