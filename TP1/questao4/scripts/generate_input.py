#!/usr/bin/env python
# ARGS: <number_of_numbers_to_genearate> <'A'|'B'> [path/to/output/file]
from os.path import abspath
from time import sleep
import random
import sys
import numpy as np
import matplotlib.pyplot as plt

INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize-1

# | numpy    | C
# +----------+---------------
# | np.int32 | int32_t / char
# | np.int64 | int64_t
# | np.intc  | int
def generate(n, unique=False):
  if unique:
    return np.random.choice(n*2, size=n, replace=False) ## .dtype == int64
  return np.random.randint(low=INT_MIN, high=INT_MAX+1, size=n, dtype=np.int64)

def save_arr(arr, filename):
  return arr.tofile(filename, sep=" ", format="%i")
  # fd = open(filename, mode='wb')
  # arr.tofile(fd)
  # fd.close


# TODO:
def generate_to_case_A(n):
  return generate(n)

def generate_to_case_B(n):
  return generate(n, unique=True)

switcher_cases = {
  'A': generate_to_case_A,
  'B': generate_to_case_B,
}

if __name__ == "__main__":
  if len(sys.argv) >= 3:
    N, case = int(sys.argv[1]), sys.argv[2]
    output_filename = sys.argv[3] if len(sys.argv) > 3 else None

    if (N > 0):
      print("...")
      selected_generator = switcher_cases.get(case, lambda: "Invalid case")
      data_generated = selected_generator(N)
      sleep(1)
      if (output_filename):
        save_arr(data_generated, abspath(output_filename))
      else:
        print(data_generated)
  else:
    print( f"USAGE {sys.argv[0]} <number_of_numbers_to_genearate> <'A'|'B'> [path/to/output/file]" )
