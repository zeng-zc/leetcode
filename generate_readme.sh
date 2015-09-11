#!/bin/sh
cat > README.md <<EOF
# Summary
Codes I wrote to solve the problems on [leetcode](https://leetcode.com/).

Most of the codes in *Algorithm* section are written in C++ and C, 

and a few in Python, while the *Shell* section is in Perl.

A lot of the problems are solved in several ways, i.e. the naiive one and improved one.

Advices and discussions are welcome to Email to zengzhongchao@gmail.com.

Enjoy it.

EOF
./generate_readme_catalogue.pl >> README.md
