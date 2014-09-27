# epdb2 --- experiment program 2 for python debugger testing


import pdb


def combine(a, b):
    """ sandwiches b in two copies of a and wrap by double quotes"""
    c = '"' + a + b + a + '"'
    return c

a = "aaa"
pdb.set_trace()
b = "bbb"
c = "ccc"
final = combine(a, b)
print final
