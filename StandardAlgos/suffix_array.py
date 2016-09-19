""" This module create suffix array in O(N log^2 N) """

import sys


class Entry:
    """ entry class which holds rank of s[i] and s[i + 1] suffix """
    def __init__(self):
        self.p = 0
        self.nr = [0, 0]

    def __cmp__(self, other):
        if self.nr[0] == other.nr[0]:
            return self.nr[1].__cmp__(other.nr[1])
        else:
            return self.nr[0].__cmp__(other.nr[0])

MAXLG = 17
MAXN = 1010
P = [[] for x in xrange(MAXLG)]
L = []


# @param text input string
# @return list suffix array if text
def buidlSuffixArray(text):
    """ build suffix array of text """
    global L
    global P

    N = len(text)
    c = ord('A')

    for i in xrange(len(P)):
        P[i] = [0 for x in xrange(N)]

    L = [Entry() for x in xrange(N)]

    for i in xrange(N):
        P[0][i] = ord(text[i]) - c

    stp = 1
    cnt = 1

    while (cnt >> 1) < N:
        for i in xrange(N):
            L[i].nr[0] = P[stp - 1][i]
            L[i].nr[1] = P[stp - 1][cnt + i] if cnt + i < N else -1
            L[i].p = i

        # sort
        L.sort()

        # build P[stp][]
        for i in xrange(N):
            if (i > 0 and L[i].nr[0] == L[i - 1].nr[0]
               and L[i].nr[1] == L[i - 1].nr[1]):
                P[stp][L[i].p] = P[stp][L[i - 1].p]
            else:
                P[stp][L[i].p] = i
        # increment vars
        cnt <<= 1
        stp += 1

    sa = []
    for el in L:
        sa.append(el.p)
    # print sa
    return sa


def lcp(a, b, stp, N):
    global P
    if a == b:
        return N - a
    cnt = 0
    k = stp
    while k >= 0 and a < N and b < N:
        if P[k][a] == P[k][b]:
            a += 1 << k
            b += 1 << k
            cnt += 1 << k
        k -= 1
    return cnt


def solve():
    # http://www.spoj.com/problems/DISUBSTR/
    t = int(sys.stdin.readline())
    for _ in xrange(t):
        s = sys.stdin.readline().strip()
        N = len(s)
        # cacl stp
        stp = 1
        cnt = 1
        while cnt >> 1 < N:
            stp += 1
            cnt <<= 1

        sa = buidlSuffixArray(s)
        ret = 0
        for i in xrange(N):
            if i > 0:
                # suffix len - common prefix = distinct substr
                ret += (N - sa[i]) - lcp(sa[i - 1], sa[i], stp - 1, N)
            else:
                ret = N - sa[0]
        print ret


if __name__ == '__main__':
    solve()
