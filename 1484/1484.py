def process():
	arr=list(map(int,input().split()))
	v=[0 for _ in range(7)]
	ans=0
	for i in arr:
		v[i]+=1
	idx1=0
	idx2=0
	for i in range(1,7):
		if v[i]>=v[idx1]:
			idx2=idx1
			idx1=i
		elif v[i]>=v[idx2]:
			idx2=i
	if v[idx1]==4:
		re=50000+idx1*5000
	elif v[idx1]==3:
		re=10000+idx1*1000
	elif v[idx1]==2:
		if v[idx2]==2:
			re=2000+idx1*500+idx2*500
		else: re=1000+idx1*100
	else: re=idx1*100

	return re

ans=0

for _ in range(int(input())):
	tmp=process()
	if ans<tmp:
		ans=tmp

print(ans)
