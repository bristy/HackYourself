# http://codeforces.com/problemset/problem/14/D


from sys import stdin


def readInt(): return map(int, stdin.readline().split())

n, = readInt()
graph = [[] for _ in xrange(n)]
adjMat = [[0 for _ in xrange(n)] for _ in xrange(n)]

# dfs for tree


def dfs(u, f=-1):
    d = [0, u]
    for v in graph[u]:
        if v != f and adjMat[u][v] == 1:
            p = dfs(v, u)
            p[0] += 1
            if d < p:
                d = p
    return d


# read tree
for _ in xrange(n - 1):
    a, b = readInt()
    a -= 1
    b -= 1
    graph[a] += [b]
    graph[b] += [a]
    adjMat[a][b] = adjMat[b][a] = 1
ret = 0
for a in xrange(n):
    for b in xrange(a, n):
        if adjMat[a][b] == 1:
            adjMat[a][b] = 0
            adjMat[b][a] = 0
            p = dfs(dfs(a)[1])[0]  # find diameter of tree with root a
            q = dfs(dfs(b)[1])[0]  # find deameter of tree wiht root b
            ret = max(ret, p * q)
            adjMat[a][b] = adjMat[b][a] = 1
print ret
