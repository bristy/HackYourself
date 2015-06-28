"""
simple thread exaple
"""


import threading


def worker(num):
    """
    Thread worker funtion
    """
    print "Worker: %s" % num
    return

for i in xrange(5):
    t = threading.Thread(target=worker, args=(i,))
    t.start()
