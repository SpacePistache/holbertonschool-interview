#!/usr/bin/env python3
"""Solves the N-Queens puzzle using backtracking."""

import sys


def valid_movement(chessboard):
    """Return True if no two queens on the board attack each other."""
    for i in range(len(chessboard)):
        for j in range(i + 1, len(chessboard)):
            if chessboard[i] == chessboard[j]:
                return False
            if abs(i - j) == abs(chessboard[i] - chessboard[j]):
                return False
    return True


def solve(chessboard, n):
    """Place queens row by row, printing every complete valid board."""
    if len(chessboard) == n:
        print([[row, col] for row, col in enumerate(chessboard)])
        return

    for col in range(n):
        chessboard.append(col)
        if valid_movement(chessboard):
            solve(chessboard, n)
        chessboard.pop()


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve([], n)
