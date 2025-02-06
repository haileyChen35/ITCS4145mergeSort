import numpy as np
import matplotlib.pyplot as plt
import re


with open("result.txt", "r") as file:
    data = file.readlines()


sizes = []
times = []

for line in data:
    match = re.search(r"size:\s*(\d+)\s*time:\s*([\d.e-]+)", line)
    if match:
        sizes.append(int(match.group(1)))  # Extract integer size
        times.append(float(match.group(2)))  # Extract time as float

plt.figure(figsize=(8, 5))
plt.plot(sizes, times, marker='o', linestyle='-', color='blue')

plt.xscale('log')
plt.yscale('log')


plt.xlabel("Size")
plt.ylabel("Time (seconds)")
plt.title("Benchmark of MergeSort")

plt.savefig('myplot.png') 

plt.show()
