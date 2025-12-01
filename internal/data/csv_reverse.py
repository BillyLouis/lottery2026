#!/usr/bin/env python3
# csv_reverse.py
# Usage: python3 csv_reverse.py input.csv output.csv [--has-header]
import sys
import csv

def reverse_csv(infile, outfile, has_header=False):
    with open(infile, newline='') as f:
        rows = list(csv.reader(f))
    header = []
    if has_header and rows:
        header = [rows[0]]
        rows = rows[1:]
    rows.reverse()
    with open(outfile, 'w', newline='') as f:
        writer = csv.writer(f)
        if header:
            writer.writerows(header)
        writer.writerows(rows)

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: csv_reverse.py input.csv output.csv [--has-header]")
        sys.exit(1)
    infile = sys.argv[1]
    outfile = sys.argv[2]
    has_header = "--has-header" in sys.argv
    reverse_csv(infile, outfile, has_header)
    print(f"Wrote reversed CSV to {outfile}")
