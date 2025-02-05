import numpy as np
import matplotlib.pyplot as plt

sizes = np.array([10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000])
times = np.array([1.9e-05, 0.000147, 0.001535, 0.016352, 0.171602, 1.7903, 18.7148, 194.392, 2016.56])

plt.figure(figsize=(8, 5))
plt.plot(sizes, times, marker='o', linestyle='-', color='blue')

plt.xscale('log')
plt.yscale('log')


plt.xlabel("Size")
plt.ylabel("Time (seconds)")
plt.title("Benchmark of MergeSort")


plt.show()