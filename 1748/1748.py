N=input()
n=len(N)
number=int(N)
answer=0
for i in range(0,n):
	answer+=number-pow(10,i)+1

print(answer)
