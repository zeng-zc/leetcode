# https://leetcode.com/problems/valid-phone-numbers/
perl -ne 'print if /^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$/'
