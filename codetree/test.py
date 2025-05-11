# test.py

memo = [-1]*11


def padovan(n):
    if memo[n] != -1:
        return memo[n]
    if n <= 3:
        memo[n] = 1
    else:
        memo[n] = padovan(n - 2) + padovan(n - 3)
        print(n, memo[n])

    return memo[n]


padovan(10)
