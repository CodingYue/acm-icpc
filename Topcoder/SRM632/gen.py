from random import *
x = []
n = 2000
for i in range(n):
	tmp = (randint(0, n - 1), randint(0, n-1))
	while True:
		tmp = (randint(0, n - 1), randint(0, n-1))
		yes = True
		for j in x:
			if j == tmp:
				yes = False
				break
		if yes:
			break
	x.append(tmp)

