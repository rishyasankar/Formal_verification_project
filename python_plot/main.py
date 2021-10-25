import matplotlib.pyplot as plt
import numpy as np
from numpy import asarray

s = [[[0 for k in range(30)] for j in range(24)] for i in range(5)]
zz = 0
y = 0
## Read the output from cpp and gather all segment info for different time instances
with open("data", 'r') as fp:
    for line in fp:
        if "Time" in line:
            zz = zz + 1
            y = 0
        else:
            # print(len([int(n) for n in line.split(',')[:-1]]))
            # print(len(s[zz-1][y]))
            s[zz - 1][y] = [int(n) for n in line.split(',')[:-1]]
            y = y + 1

fp.close()
'''
##Print to check non zero elements in time 0
for k in range(len(s[0])):
    for j in range(len(s[0][k])):
        if s[0][k][j] > 0 :
            print(s[0][k][j])

'''

for i in range(len(s)):
    for j in range(len(s[i])):
        for k in range(len(s[i][j])):
            if s[i][j][k] == 0:
                s[i][j][k] = -5
## Constructing the global matrix to represent the road

gm = [[[-10 for k in range(67)] for j in range(67)] for i in range(5)]

z = 0

## Vertical segments update

while z <= zz:
    gm[z][2][0], gm[z][3][0], gm[z][4][0], gm[z][5][0], gm[z][6][0], gm[z][7][0], gm[z][8][0], gm[z][9][0], gm[z][10][
        0], gm[z][11][0], gm[z][12][0], gm[z][13][0], gm[z][14][0], gm[z][15][0], gm[z][16][0], gm[z][17][0], gm[z][18][
        0], gm[z][19][0], gm[z][20][0], gm[z][21][0], gm[z][22][0], gm[z][23][0], gm[z][24][0], gm[z][25][0], gm[z][26][
        0], gm[z][27][0], gm[z][28][0], gm[z][29][0], gm[z][30][0], gm[z][31][0] = s[z][13][::-1]
    gm[z][2][1], gm[z][3][1], gm[z][4][1], gm[z][5][1], gm[z][6][1], gm[z][7][1], gm[z][8][1], gm[z][9][1], gm[z][10][
        1], gm[z][11][1], gm[z][12][1], gm[z][13][1], gm[z][14][1], gm[z][15][1], gm[z][16][1], gm[z][17][1], gm[z][18][
        1], gm[z][19][1], gm[z][20][1], gm[z][21][1], gm[z][22][1], gm[z][23][1], gm[z][24][1], gm[z][25][1], gm[z][26][
        1], gm[z][27][1], gm[z][28][1], gm[z][29][1], gm[z][30][1], gm[z][31][1] = s[z][12]
    gm[z][2][32], gm[z][3][32], gm[z][4][32], gm[z][5][32], gm[z][6][32], gm[z][7][32], gm[z][8][32], gm[z][9][32], \
    gm[z][10][32], gm[z][11][32], gm[z][12][32], gm[z][13][32], gm[z][14][32], gm[z][15][32], gm[z][16][32], gm[z][17][
        32], gm[z][18][32], gm[z][19][32], gm[z][20][32], gm[z][21][32], gm[z][22][32], gm[z][23][32], gm[z][24][32], \
    gm[z][25][32], gm[z][26][32], gm[z][27][32], gm[z][28][32], gm[z][29][32], gm[z][30][32], gm[z][31][32] = s[z][22][
                                                                                                              ::-1]
    gm[z][2][33], gm[z][3][33], gm[z][4][33], gm[z][5][33], gm[z][6][33], gm[z][7][33], gm[z][8][33], gm[z][9][33], \
    gm[z][10][33], gm[z][11][33], gm[z][12][33], gm[z][13][33], gm[z][14][33], gm[z][15][33], gm[z][16][33], gm[z][17][
        33], gm[z][18][33], gm[z][19][33], gm[z][20][33], gm[z][21][33], gm[z][22][33], gm[z][23][33], gm[z][24][33], \
    gm[z][25][33], gm[z][26][33], gm[z][27][33], gm[z][28][33], gm[z][29][33], gm[z][30][33], gm[z][31][33] = s[z][23]
    gm[z][2][64], gm[z][3][64], gm[z][4][64], gm[z][5][64], gm[z][6][64], gm[z][7][64], gm[z][8][64], gm[z][9][64], \
    gm[z][10][64], gm[z][11][64], gm[z][12][64], gm[z][13][64], gm[z][14][64], gm[z][15][64], gm[z][16][64], gm[z][17][
        64], gm[z][18][64], gm[z][19][64], gm[z][20][64], gm[z][21][64], gm[z][22][64], gm[z][23][64], gm[z][24][64], \
    gm[z][25][64], gm[z][26][64], gm[z][27][64], gm[z][28][64], gm[z][29][64], gm[z][30][64], gm[z][31][64] = s[z][6][
                                                                                                              ::-1]
    gm[z][2][65], gm[z][3][65], gm[z][4][65], gm[z][5][65], gm[z][6][65], gm[z][7][65], gm[z][8][65], gm[z][9][65], \
    gm[z][10][65], gm[z][11][65], gm[z][12][65], gm[z][13][65], gm[z][14][65], gm[z][15][65], gm[z][16][65], gm[z][17][
        65], gm[z][18][65], gm[z][19][65], gm[z][20][65], gm[z][21][65], gm[z][22][65], gm[z][23][65], gm[z][24][65], \
    gm[z][25][65], gm[z][26][65], gm[z][27][65], gm[z][28][65], gm[z][29][65], gm[z][30][65], gm[z][31][65] = s[z][7]

    gm[z][34][0], gm[z][35][0], gm[z][36][0], gm[z][37][0], gm[z][38][0], gm[z][39][0], gm[z][40][0], gm[z][41][0], \
    gm[z][42][0], gm[z][43][0], gm[z][44][0], gm[z][45][0], gm[z][46][0], gm[z][47][0], gm[z][48][0], gm[z][49][0], \
    gm[z][50][0], gm[z][51][0], gm[z][52][0], gm[z][53][0], gm[z][54][0], gm[z][55][0], gm[z][56][0], gm[z][57][0], \
    gm[z][58][0], gm[z][59][0], gm[z][60][0], gm[z][61][0], gm[z][62][0], gm[z][63][0] = s[z][15][::-1]
    gm[z][34][1], gm[z][35][1], gm[z][36][1], gm[z][37][1], gm[z][38][1], gm[z][39][1], gm[z][40][1], gm[z][41][1], \
    gm[z][42][1], gm[z][43][1], gm[z][44][1], gm[z][45][1], gm[z][46][1], gm[z][47][1], gm[z][48][1], gm[z][49][1], \
    gm[z][50][1], gm[z][51][1], gm[z][52][1], gm[z][53][1], gm[z][54][1], gm[z][55][1], gm[z][56][1], gm[z][57][1], \
    gm[z][58][1], gm[z][59][1], gm[z][60][1], gm[z][61][1], gm[z][62][1], gm[z][63][1] = s[z][14]
    gm[z][34][32], gm[z][35][32], gm[z][36][32], gm[z][37][32], gm[z][38][32], gm[z][39][32], gm[z][40][32], gm[z][41][
        32], gm[z][42][32], gm[z][43][32], gm[z][44][32], gm[z][45][32], gm[z][46][32], gm[z][47][32], gm[z][48][32], \
    gm[z][49][32], gm[z][50][32], gm[z][51][32], gm[z][52][32], gm[z][53][32], gm[z][54][32], gm[z][55][32], gm[z][56][
        32], gm[z][57][32], gm[z][58][32], gm[z][59][32], gm[z][60][32], gm[z][61][32], gm[z][62][32], gm[z][63][32] = \
    s[z][20][::-1]
    gm[z][34][33], gm[z][35][33], gm[z][36][33], gm[z][37][33], gm[z][38][33], gm[z][39][33], gm[z][40][33], gm[z][41][
        33], gm[z][42][33], gm[z][43][33], gm[z][44][33], gm[z][45][33], gm[z][46][33], gm[z][47][33], gm[z][48][33], \
    gm[z][49][33], gm[z][50][33], gm[z][51][33], gm[z][52][33], gm[z][53][33], gm[z][54][33], gm[z][55][33], gm[z][56][
        33], gm[z][57][33], gm[z][58][33], gm[z][59][33], gm[z][60][33], gm[z][61][33], gm[z][62][33], gm[z][63][33] = \
    s[z][21]
    gm[z][34][64], gm[z][35][64], gm[z][36][64], gm[z][37][64], gm[z][38][64], gm[z][39][64], gm[z][40][64], gm[z][41][
        64], gm[z][42][64], gm[z][43][64], gm[z][44][64], gm[z][45][64], gm[z][46][64], gm[z][47][64], gm[z][48][64], \
    gm[z][49][64], gm[z][50][64], gm[z][51][64], gm[z][52][64], gm[z][53][64], gm[z][54][64], gm[z][55][64], gm[z][56][
        64], gm[z][57][64], gm[z][58][64], gm[z][59][64], gm[z][60][64], gm[z][61][64], gm[z][62][64], gm[z][63][64] = \
    s[z][4][::-1]
    gm[z][34][65], gm[z][35][65], gm[z][36][65], gm[z][37][65], gm[z][38][65], gm[z][39][65], gm[z][40][65], gm[z][41][
        65], gm[z][42][65], gm[z][43][65], gm[z][44][65], gm[z][45][65], gm[z][46][65], gm[z][47][65], gm[z][48][65], \
    gm[z][49][65], gm[z][50][65], gm[z][51][65], gm[z][52][65], gm[z][53][65], gm[z][54][65], gm[z][55][65], gm[z][56][
        65], gm[z][57][65], gm[z][58][65], gm[z][59][65], gm[z][60][65], gm[z][61][65], gm[z][62][65], gm[z][63][65] = \
    s[z][5]

    gm[z][0][2:32] = s[z][11]
    gm[z][1][2:32] = s[z][10][::-1]
    gm[z][0][34:64] = s[z][9]
    gm[z][1][34:64] = s[z][8][::-1]

    gm[z][32][2:32] = s[z][16]
    gm[z][33][2:32] = s[z][17][::-1]
    gm[z][32][34:64] = s[z][18]
    gm[z][33][34:64] = s[z][19][::-1]

    gm[z][64][2:32] = s[z][0]
    gm[z][65][2:32] = s[z][1][::-1]
    gm[z][64][34:64] = s[z][2]
    gm[z][65][34:64] = s[z][3][::-1]

    z = z + 1

plt.imshow(gm[0], cmap='gray', interpolation='nearest', )
plt.ylim(-1, 67)
plt.xlim(-1,67)
plt.title("Car position on the road")
plt.show()
