t = int(raw_input())
for x in xrange(t):
    r = raw_input()
    kiss = True
    a = r[0]
    for el in r[1:]:
        if el == a:
            kiss = False
            break
        a = el
    if kiss:
        print "KISS"
    else:
        print "SLAP"
