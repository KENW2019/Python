from func_myabs import my_abs
from func_nop import nop
from func_move import move
from func_quadratic import quadratic
from func_power import power
from func_variablePara import calc
from func_dictPara import person

'''print(my_abs(-1,2))
print(nop())'''


''' test func abs'''
'''
#my_abs('A')
my_abs(-9)

#abs('A')
'''

''' test func move'''
'''
r = move(1,2,3,)
print(r)

x,y = move(1,2,3,)
print(x,y)
'''

''' test func quadratic'''
'''
print('quadratic(2, 3, 1) =', quadratic(2, 3, 1))
print('quadratic(1, 3, -4) =', quadratic(1, 3, -4))
'''

''' test func power '''
'''
print(power(2))
print(power(2,3))
print(power(3,3))
'''


''' variable para V1 '''
'''
print(calc([1, 2, 3]))
print(calc((1, 3, 5, 7)))
'''

''' variable para V2 '''
'''
print(calc(1,2,3))
print(calc(1, 3, 5, 7))
print(calc())

nums = [1, 2, 3]
print(calc(*nums))
'''

''' func_dictPara'''
person('Michael', 30)
person('Bob', 35, city='Beijing')
person('Adam', 45, gender='M', job='Engineer')

extra = {'city': 'Beijing', 'job': 'Engineer'}
person('dapei','34',**extra)






