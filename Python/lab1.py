demandinputfilename = 'demand.txt'
distanceinputfilename = 'distance.txt'
outputfilename = 'result.lp'

with open(demandinputfilename) as d:
    demand = d.readlines()
with open(distanceinputfilename) as f:
    distance = f.readlines()
result = open(outputfilename, "w")

ObjStr = "Minimize\nObj:\n"
row_index = 1
for demand_row, distance_row in zip(demand, distance):
    demand_row = list(map(int, demand_row.split(' ')))
    distance_row = list(map(int, distance_row.split(' ')))
    col_index = 1
    for demand_col, distance_col in zip(demand_row, distance_row):
        ObjStr = ObjStr + str(demand_col * distance_col) + " " + "X" + str(row_index) + str(col_index) + " + "
        col_index += 1
    ObjStr += '\n'
    row_index += 1
ObjStr = ObjStr[:-4] + "\n\nSubject to\n"
row_index = 1
for row in distance:
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