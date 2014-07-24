#http://www.hackerearth.com/devfactory-hiring-challenge/algorithm/geeko-and-tree-2/
t = int(raw_input())

for i in range(t):
    inp = (raw_input()).split(" ")
    k = int(inp[0])
    n = int(inp[1])

    nodes = 1
    curr = 1
    for level in range(n):
        curr = curr*k
        nodes = nodes + curr

    weird = 0
    while nodes > 0:
        weird = weird + nodes%10
        nodes = nodes /10

    print weird
        
