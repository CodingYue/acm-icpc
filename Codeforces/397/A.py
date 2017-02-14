n = input()
home = raw_input().strip()

degree = 0

for _ in xrange(n):
    a, b = raw_input().strip().split("->")
    # print a, b
    if a == home:
        degree += 1
    else:
        if b == home:
            degree -= 1

if degree == 0:
    print "home"
else:
    print "contest"
