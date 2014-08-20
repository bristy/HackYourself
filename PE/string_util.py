# this module has all string related algorithm

def is_permutation(string1, string2):
    """ check if string1 is permutation of string2 """
    return len(string1) == len(string2) and sorted(string1) == sorted(string2)

