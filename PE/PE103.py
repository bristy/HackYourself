#Let S(A) represent the sum of elements in set A of size n. We shall call it a
#special sum set if for any two non-empty disjoint subsets, B and C, the following properties are true:

#S(B) != S(C); that is, sums of subsets cannot be equal.
#If B contains more elements than C then S(B) > S(C).
#If S(A) is minimised for a given n, we shall call it an optimum special sum set. The first five optimum special sum sets are given below.

#n = 1: {1}
#n = 2: {1, 2}
#n = 3: {2, 3, 4}
#n = 4: {3, 5, 6, 7}
#n = 5: {6, 9, 11, 12, 13}

#It seems that for a given optimum set, A = {a1, a2, ... , an}, the next optimum set is of the form B = {b, a1+b, a2+b, ... ,an+b}, where b is the "middle" element on the previous row.

#By applying this "rule" we would expect the optimum set for n = 6 to be A = {11, 17, 20, 22, 23, 24}, with S(A) = 117. However, this is not the optimum set, as we have merely applied an algorithm to
#provide a near optimum set. The optimum set for n = 6 is A = {11, 18, 19, 20, 22, 25}, with S(A) = 115 and corresponding set string: 111819202225.

#Given that A is an optimum special sum set for n = 7, find its set string.

best = 10000000
ret = ''

def getSum(subset):
    sum = 0
    for el in subset:
        sum = sum + el
    return sum


def check(subset):
    #print "processing   "
    #print subset
    size = len(subset)
    isGood = True
    for i in range(1<<size):
        subsetOne = []
        subsetTwo = []

        for j in range(size):
            #print i&(1<<j)
            if (i & (1<<j)) > 0:
                subsetOne.append(subset[j])
            else:
                subsetTwo.append(subset[j])

        #check two properties
        sOne = getSum(subsetOne)
        sTwo = getSum(subsetTwo)
        if sOne == sTwo:
            isGood = False
            break
        #print "subsets one and two ##"
        #print subsetOne
        #print subsetTwo
    #check for second rule
    sum1 = subset[0]
    sum2 = 0
    for i in range(len(subset)/2):
        sum1 = sum1 + subset[i+1]
        sum2 = sum2 + subset[-i-1]
        if(sum1 <= sum2):
            isGood = False
            break    if isGood:
        return getSum(subset)
    else :
        return -1

def gen(size, default,  subset):
    global best
    global ret
    global done
    #if we have generated a required set then process it
    if size == len(subset):
        sum= check(subset)
        if sum != -1:
            if best > sum:
                best = sum
                for el in subset:
                    ret = ret + str(el)
        return
    lower = default
    if len(subset) > 0:
        lower = subset[-1] + 1
    for i in range(lower, 50):
        if len(subset) < size:
            subset.append(i)
            gen(size, default,  subset)
            #restore it again
            subset.pop()


if __name__ == '__main__':
    print "start"
    gen(7, 20, [])
    print best
    print ret

