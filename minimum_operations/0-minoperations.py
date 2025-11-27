def minOperations(n):
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
