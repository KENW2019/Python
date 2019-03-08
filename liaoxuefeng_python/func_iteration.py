
from collections import Iterable

'''
print(isinstance('abc',Iterable))
print(isinstance([1,2,3],Iterable))
print(isinstance(123,Iterable))

for i,value in enumerate(['A','B','C']):
    print(i,value)

for x,y in [(1,1),(2,4),(3,9)]:
    print(x,y)
'''

def findMinAndMax(L):
    if len(L) == 0:
        return (None,None)
    
    if len(L) == 1:
        return (L[0],L[0])
    
    if len(L) >= 2:
        min = L[0]
        max = L[0]
        for x in L:
            if x < min:
                min = x
            if x > max:
                max = x
        return (min,max)





