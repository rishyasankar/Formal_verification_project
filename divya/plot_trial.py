import matplotlib.pyplot as plt

# read data from file : for each row : 4 lights
# each light will have a particular point assigned
# and based on the value colour changes
# 0 = black, 1 = red and 2 = green
# repeat for each row

with open ("outputfile", 'r') as f:
  lines = f.readlines ()


x = [[1,1.5,1,0.5]]
y = [[61.5,61,60.5,61]]

il = [[1,2,0,1], [2,1,0,1], [2,1,0,0], [1,0,1,2], [1,1,2,1], [1,2,1,0], [0,0,2,1], [0,1,2,1], [0,2,1,0]]

for i in range(1):
  print(il[i]) 
  for j in range(len(il[i])):
    print(j)
    if il[i][j] == 1:
      colour = "red"
    elif il[i][j] == 2:
      colour = "green"
    else:
      colour = "black"
    xi = x[i][j]
    yi = y[i][j]
    plt.scatter (xi, yi, color = colour)


    



plt.show ()
