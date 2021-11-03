##for plotting traffic system at different time intervals showing switching of lights
import matplotlib.pyplot as plt

m = 0
g_sig = [[[m for i in range(4)] for j in range(9)] for k in range(1800)]
z=0
yy = 0


with open ("output_traffic3.txt",'r') as f:
  for line in f:
    if "time" in line:
      z = z+1
      yy = 0
    else:
      tmp_lst = []
      for g in line.split():
          tmp_lst.append(int(g))
      g_sig[z-1][yy] = tmp_lst
      yy = yy+1
      

x = [[1, 3, 1, -1], [31, 33, 31, 29], [61, 63, 61, 59], [1, 3, 1, -1], [31, 33, 31, 29], [61, 63, 61, 59], [1, 3, 1, -1], [31, 33, 31, 29], [61, 63, 61, 59]]

y = [[63, 61, 59, 61], [63, 61, 59, 61], [63, 61, 59, 61], [33, 31, 29, 31], [33, 31, 29, 31], [33, 31, 29, 31], [3, 1, -1, 1], [3, 1, -1, 1], [3, 1, -1, 1]]

size=100
t=0

for z in range(1800):
  for i in range(9):
    for j in range(len(g_sig[z][i])):
      if g_sig[z][i][j] == 1:
        colour = "red"
      elif g_sig[z][i][j] == 2:
        colour = "green"
      else:
        colour = "black"
      xi = x[i][j]
      yi = y[i][j]
      plt.scatter (xi, yi,s=size, color = colour)
      name = "notraffic"+str(z)+".png"
      plt.title('time=%d' %t)
      plt.savefig(name)
  t=t+2
  print("saved")
  
