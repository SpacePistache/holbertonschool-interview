#!/usr/bin/python3
"""
Module: 0-minoperations
This module contains a function that calculates the minimum number
of operations needed to obtain exactly `n` H characters in a text file
using only two operations: Copy All and Paste.

The strategy is based on breaking the target number `n` into its
prime factors. Each prime factor represents the optimal sequence of
operations (one Copy All + multiple Pasts).
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result
    in exactly `n` H characters.

    The only allowed operations are:
        - Copy All
        - Paste

    The approach:
        The optimal strategy is based on prime factorization.
        For each factor `f`:
            - 1 operation is needed to Copy All
            - (f - 1) operations are needed to Paste
          Total = f operations per factor

        Therefore, the minimal number of operations required is
        the sum of all prime factors of `n`.

    Args:
        n (int): The target number of H characters.

    Returns:
        int: The minimum number of operations needed.
             Returns 0 if `n` is impossible to achieve or < 2.
    """
    if n < 2:
        return 0

    ops = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            ops += divisor
            n //= divisor
        divisor += 1
    return ops
