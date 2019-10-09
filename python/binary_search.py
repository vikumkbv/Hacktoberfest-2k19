def binary_search(lower,upper,key,list):
	if(lower>upper):
		return -1
	if(list[upper] == key):
		return upper
	if(list[lower] == key):
		return lower
	mid = (upper+lower)//2
	if(list[mid] == key):
		return mid
	if(list[mid]<key):
		return binary_search(mid+1,upper,key,list)
	if(list[mid]>key):
		return binary_search(lower,mid-1,key,list)

x = input().split()
list = []
for i in range(len(x)):
	list.append(int(x[i]))

key = int(input())

ans = binary_search(0,len(list)-1,key,list)

print(ans)
