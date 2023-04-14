#!/usr/bin/python3
""" """

def minOperations(n):
    """ """
    if n <= 1:
        return 0
    i = 2
    ops = 0
    while i <= n:
        if n % i == 0:
            ops += i
            n /= i
        else:
            i += 1
    return ops
