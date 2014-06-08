def f(x, w):
	if x % w == 1: return True
	if x < w: return True
	if x % w == 0: return False
	if x % (x % w) != 0: return False 
	return f(x / (x % w), w)
l, r = map(int, raw_input().split(' '))
w = input()
cnt = 0
for i in range(l, r + 1):
	if f(i, w):
		cnt += 1
		print i

cnt = 0
for t in range(2, w):
	if 36 * t % w == t:
		print 36 * t
		cnt += 1
print f(72, w)
print cnt