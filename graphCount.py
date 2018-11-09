import numpy as np
import matplotlib.pyplot as plt

splits = [1, 10, 20, 50, 100]
times = np.zeros(5)

file = open("playlist.txt","r")

for line in file:
  fields = line.split(" ")
  
  for i in range(len(fields)):
      times[i] = fields[i]
  
plt.plot(splits, times)