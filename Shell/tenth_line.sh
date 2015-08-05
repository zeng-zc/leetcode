# https://leetcode.com/problems/tenth-line/
# Read from the file file.txt and output the tenth line to stdout.

perl -ne 'if ($. == 10){print}' file.txt
