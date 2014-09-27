# https://projecteuler.net/problem=182

import algos


def solve():
    p = 1009
    q = 3643
    n = p * q
    phi = (p - 1) * (q - 1)
    esum = 0
    for e in xrange(2, phi):
        if algos.gcd(phi, e) == 1 and unconcealedMessages(e, p, q) == 9:
            esum += e
    print esum
    return esum

def unconcealedMessages(e, p, q):
    """ number of unconcealed messages are given by
    [1 + gcd(p-1, e-1)]*[1 + gcd(q-1, e-1)]
    """
    return (1 +  algos.gcd(p - 1, e - 1)) * (1 + algos.gcd(q - 1, e - 1))

if __name__ == '__main__':
    solve()
