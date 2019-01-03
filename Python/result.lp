Minimize
Obj:
0 X11 + 90 X12 + 70 X13 + 100 X14 + 
36 X21 + 0 X22 + 24 X23 + 56 X24 + 
49 X31 + 42 X32 + 0 X33 + 42 X34 + 
50 X41 + 70 X42 + 30 X43 + 0 X44

Subject to
C: X11 + X12 + X13 + X14 = 1
C: X21 + X22 + X23 + X24 = 1
C: X31 + X32 + X33 + X34 = 1
C: X41 + X42 + X43 + X44 = 1

C: X11 - Y1 <= 0
C: X12 - Y2 <= 0
C: X13 - Y3 <= 0
C: X14 - Y4 <= 0
C: X21 - Y1 <= 0
C: X22 - Y2 <= 0
C: X23 - Y3 <= 0
C: X24 - Y4 <= 0
C: X31 - Y1 <= 0
C: X32 - Y2 <= 0
C: X33 - Y3 <= 0
C: X34 - Y4 <= 0
C: X41 - Y1 <= 0
C: X42 - Y2 <= 0
C: X43 - Y3 <= 0
C: X44 - Y4 <= 0

C: Y1 + Y2 + Y3 + Y4 = 2

Integer
X11 X12 X13 X14 
X21 X22 X23 X24 
X31 X32 X33 X34 
X41 X42 X43 X44 
Y1 Y2 Y3 Y4 

End