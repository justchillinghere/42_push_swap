#!/bin/bash

python3 tester.py
export ARG=$(cat random_integers.txt)
./a.out $ARG | ./checker_Mac $ARG