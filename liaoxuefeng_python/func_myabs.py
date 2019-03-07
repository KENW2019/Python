
''' my_abs v1'''
'''
def my_abs(x):
    if x>=0:
        return x
    else:
        return -x
'''


''' my_abs v1'''
''' check input para'''
def my_abs(x):
    if not isinstance(x,(int,float)):
        raise TypeError('bad operand type')
    else:
        if x >= 0:
            y = x
        else:
            y = -x
    print(y)
    return y

