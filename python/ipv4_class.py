import re
def check(l):
    for i in l:
        i=int(i)
        if i<=255 and i>=0:
            f=True
        else:
            f=False
            break
    return f
pattern =re.compile(r'^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$')

test=input("Enter the IPv4 address :")
#print(pattern)
matches=pattern.finditer(test)
#print(matches)
l=list()
for match in matches:
    l=match.group(0)
if len(l)>0:
    l=l.split('.')
    for i in l:
        if len(i)>=2 and int(i[0])==0:
            f=False
            break
    else:
        f=True
    ans=''
    k=1
    #print(f)
    if f:
        for i in l[1:]:
            if int(i)>=0 and int(i)<=255:
                f=False
        else:
            f=True
    #print("For loop",f)
    if len(l[0])>=2 and l[0][0]==0:
        f=False
    if f:
            i=l[0]
            #print(i)
            i=int(i)
            if i<=127 and i>=0:
                if check(l[1:]):
                    ans="This is a Class A IPv4 Address"
                    f=True
                else:
                    f=False
            elif i>=128 and i<=191:
                if check(l[1:]):
                    ans="This is a Class B IPv4 Address"
                    f=True
                else:
                    f=False
            elif i>=192 and i<=223:
                if check(l[1:]):
                    ans="This is a Class C IPv4 Address"
                    f=True
                else:
                    f=False
            elif i>=224 and i<=239:
                if check(l[1:]):
                    ans="This is a Class D IPv4 Address"
                    f=True
                else:
                    f=False
            elif i>=240 and i<=255:
                if check(l[1:]):
                    ans="This is a class E IPv4 Address"
                    f=True
                else:
                    f=False
            else:
                f=False
    else:
        f=False
    if f:
        print(ans)
    else:print("Invalid IPv4 Address entered")
else:
    print("Invalid IPv4 Address entered")
