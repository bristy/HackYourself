n = int(raw_input())
s = [int(x) for x in raw_input().split(" ")]
baj = list()
baba = list()
for el in s:
    if el % 2 == 0:
        baj.append(el)
    else:
        baba.append(el)

baj.sort()
baba.sort(reverse=True)
baj = ' '.join(str(e) for e in baj)
baba = ' '.join(str(e) for e in baba)
print baj
print baba
