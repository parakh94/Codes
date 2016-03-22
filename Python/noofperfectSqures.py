# An Efficient Method to count squares between a
# and b
import math
def CountSquares(a,b):
    return (math.floor(math.sqrt(b)) - math.ceil(math.sqrt(a)) + 1)
 
# Driver Code
a = 9
b = 25
print "Count of squares is:",int(CountSquares(a,b))
