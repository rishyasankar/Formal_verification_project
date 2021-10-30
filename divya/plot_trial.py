import matplotlib.pyplot as plt

# read data from file : for each row : 4 lights
# each light will have a particular point assigned
# and based on the value colour changes
# 0 = black, 1 = red and 2 = green
# repeat for each row
m = 0
g_sig = [[[m for i in range(4)] for j in range(9)] for k in range(1800)]
z=0
yy = 0


with open ("output.txt",'r') as f:
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
      
print(g_sig[0])
print(g_sig[1])

x = [[1, 3, 1, -1], [31, 31.5, 31, 30.5], [61, 61.5, 61, 60.5], [1, 1.5, 1, 0.5], [31, 31.5, 31, 30.5], [61, 61.5, 61, 60.5], [1, 1.5, 1, 0.5], [31, 31.5, 31, 30.5], [61, 61.5, 61, 60.5]]

y = [[63, 61, 59, 61], [61.5, 61, 60.5, 61], [61.5, 61, 60.5, 61], [31.5, 31, 30.5, 31], [31.5, 31, 30.5, 31], [31.5, 31, 30.5, 31], [1.5, 1, 0.5, 1], [1.5, 1, 0.5, 1], [1.5, 1, 0.5, 1]]

##il = [[1,2,0,1], [2,1,0,1], [2,1,0,0], [1,0,1,2], [1,1,2,1], [1,2,1,0], [0,0,2,1], [0,1,2,1], [0,2,1,0]]

for z in range(2):
  for i in range(9):
    print(g_sig[z][i]) 
    for j in range(len(g_sig[z][i])):
      print(j)
      if g_sig[z][i][j] == 1:
        colour = "red"
      elif g_sig[z][i][j] == 2:
        colour = "green"
      else:
        colour = "black"
      xi = x[i][j]
      yi = y[i][j]
      plt.scatter (xi, yi, color = colour)
      name = "os"+str(z)+".png"
      plt.savefig(name)
