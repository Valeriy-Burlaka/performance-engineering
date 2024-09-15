#!/usr/bin/env sh

time go run main.go

clang -o matrix_mult main.c && time ./matrix_mult

time python3 ./main.py
