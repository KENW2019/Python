
from student import student
'''from student import print_score'''

'''
brat = student()
print(brat)
print(student)
brat.name = 'dapei'
print(brat.name)
'''

#brat = student()
'''
bart = student('wang dapei', 59)
print(bart.name)
print(bart.score)
'''
'''
bart = student('wang dapei', 59)
bart.print_score()
print(bart.get_grade())
'''

lisa = student('wang dapei', 99)
bart = student('yazhu', 59)
print(lisa.name, lisa.get_grade())
print(bart.name, bart.get_grade())
lisa.age = 18
print(lisa.age)
print(bart.age)







