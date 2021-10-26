import matplotlib.pyplot as plt
import numpy as np

data = [[0,1,2,1], [0,1,1,1], [0,0,1,1], [0,1,1,1], [1,1,1,1], [0,1,1,1], [0,0,1,1], [0,1,1,1], [0,0,1,1]]

fig, ax = plt.subplots()

data_array = np.array(data)

"""
for i in data_array:
  for j in i:
    if j != 0:
      if j == 1:
        ax.plot(i, j, marker='x', linestyle='', ms=12, color='red')
      else:
        ax.plot(i, j, marker='o', linestyle='', ms=12, color='green')
"""
print(data_array)
print(data)

for i in data_array:
  print (i)
  for j in i:
    if j != 0:
      if j == 1:
        ax.plot(0, 0, marker='x', linestyle='', ms=12, color='red')
      else:
        ax.plot(0, 0, marker='o', linestyle='', ms=12, color='green')


plt.ylim (-1, 4)
plt.xlim (-1, 4)
plt.show ()
