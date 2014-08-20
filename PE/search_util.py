# search related methods

def binary_search(seq, val, lo = 0, hi = None):
    if hi == None:
        hi = len(seq)

    while lo<hi:
        mid = (lo + hi)/2
        midVal = seq[mid]
        if midVal < val:
            lo = mid + 1
        elif midVal > val:
            hi = mid
        else :
            return mid
    return -1
