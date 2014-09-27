""" Longest Monotonic Subsequence in 2D
There is a hypothesis floating around that SAT score is a strong indicator of
GPA. Your task is to provide the strongest counter example for this hypothesis.
Given a data set of (sat, gpa) for the final year of a group of students,
devise an algorithm to construct the longest sequence of (sati, gpai)
of students with progressively better SAT scores, and progressively
worse gpa's, i.e. sat1 < sat2 < ... < satk and gpa1 > gpa2 > ... > gpak
( Assume SAT scores and gpa's are unique ) """

# Input format
# first line an Integer reprents length of data set
# followed by N line having 2 space separated integers repesening <stai, gpai>


from sys import stdin


def getInt():
    return map(int, stdin.readline().split())


class SingleDataset:
    """ This class is used for represent single dataset in sequence"""
    def __init__(self, s, g, i):
        self.sat = s
        self.gpa = g
        self.index = i

    def __cmp__(self, other):
        if self.sat < other.sat and other.gpa < self.gpa:
            return -1
        else:
            return 1


# @param x sequence of sataset
# @return a list of longest increasing subsequence

def longestSubsequence(X):
    """ Time complexing is Nlog(N) """
    N = len(X)
    P = [0] * N  # list to store predecessor
    # M[j] stores the index k of the smallest value X[k]
    # such that there is an increasing subsequence of length j ending at X[k]
    M = [0] * (N + 1)
    L = 0

    for i in xrange(N):
        # Do binary seach for largest +ve j <= L
        # such that X[M[j]] < X[i]
        lo = 1
        hi = L
        while lo <= hi:
            mid = (lo + hi) / 2
            if X[M[mid]] < X[i]:
                lo = mid + 1
            else:
                hi = mid - 1
        newL = lo
        # predecessor of X[i] is last index of subsequence of len newL - 1
        P[i] = M[newL - 1]
        print "newL is " + str(newL)
        if newL > L:
            # if we found any subsequence longer that we have founded aleready
            # upfate M and L
            M[newL] = i
            L = newL
        elif X[i] < X[M[newL]]:
            # if we found smaller last value of subsequence lenght newL
            # update M
            M[newL] = i

    # Re-construct longest increasing subsequence
    S = [0] * L
    k = M[L]
    for i in xrange(L - 1, -1, -1):
        S[i] = X[k]
        k = P[k]

    # print longes increaing subsequence in 2D
    print "Length of Longest subsequece is: " + str(L)
    for e in S:
        print e.sat, e.gpa
    return S


if __name__ == '__main__':
    X = []
    # read input from std
    n, = getInt()
    for i in xrange(n):
        sat, gpa = getInt()
        X.append(SingleDataset(sat, gpa, i))
    X.sort()
    longestSubsequence(X)
