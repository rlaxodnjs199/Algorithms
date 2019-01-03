import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
demandinputfilename = os.path.join(THIS_FOLDER, 'demand.txt')
distanceinputfilename = os.path.join(THIS_FOLDER, 'distance.txt')
outputfilename = os.path.join(THIS_FOLDER, 'result.lp')

with open(demandinputfilename) as d:
    demand = list(map(int, d.readline().split(' ')))
with open(distanceinputfilename) as f:
    data = f.readlines()
result = open(outputfilename, "w")

ObjStr = "Minimize\nObj:\n"
row_index = 1
for row in data:
    row = map(int, row.split(' '))
    col_index = 1
    for i in row:
        ObjStr = ObjStr + str(i * demand[row_index-1]) + " " + "X" + str(row_index) + str(col_index) + " + "
        col_index += 1
    ObjStr += '\n'
    row_index += 1
ObjStr = ObjStr[:-4] + "\n\nSubject to\n"
row_index = 1
for row in data:
    col_index = 1
    row = row.split(' ')
    ObjStr += "C: "
    for i in row:
        ObjStr = ObjStr + "X" + str(row_index) + str(col_index) + " + "
        col_index += 1
    ObjStr = ObjStr[:-2] + "= 1\n"
    row_index += 1
ObjStr += '\n'
for i in range(1, row_index):
    for j in range(1, col_index):
        ObjStr = ObjStr + "C: X" + str(i) + str(j) + " - Y" + str(j) + " <= 0\n"
ObjStr = ObjStr + "\nC: "
for i in range(1, col_index):
    ObjStr = ObjStr + "Y" + str(i) + " + "
ObjStr = ObjStr[:-2] + "= 2\n\nInteger\n"
for i in range(1, row_index):
    for j in range(1, col_index):
        ObjStr = ObjStr + "X" + str(i) + str(j) + " "
    ObjStr += '\n'
for j in range(1, col_index):
    ObjStr += "Y" + str(j) + " "
ObjStr += "\n\nEnd"
result.write(ObjStr)
result.close()