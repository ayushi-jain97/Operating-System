import random

f=open("matrixA","a")



for i in range(100):
	for j in range(100):
		f.write(str(random.randint(1,10))+' ')
	f.write('\n')
