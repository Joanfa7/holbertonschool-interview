#!/usr/bin/python3
""" Set minimum operations"""


def minOperations(n):
    """  calculates the minimum number of operations required to reach the integer n by starting from 1 and either multiplying by 2 or dividing by the integer i. """
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
