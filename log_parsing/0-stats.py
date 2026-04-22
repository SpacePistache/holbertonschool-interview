#!/usr/bin/python3
"""Module that reads stdin line by line and computes metrics"""
import sys


def print_stats(total_size, status_counts):
    print("File size: {}".format(total_size))
    for code in sorted(status_counts):
        print("{}: {}".format(code, status_counts[code]))


def main():
    total_size = 0
    line_count = 0
    valid_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    status_counts = {}

    try:
        for line in sys.stdin:
            parts = line.strip().split()
            if len(parts) < 7:
                continue

            try:
                status_code = int(parts[-2])
                file_size = int(parts[-1])
            except (ValueError, IndexError):
                continue

            total_size += file_size

            if status_code in valid_codes:
                status_counts[status_code] = (
                    status_counts.get(status_code, 0) + 1
                )

            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
