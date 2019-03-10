
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

'''
lisa = student('wang dapei', 99)
bart = student('yazhu', 59)
print(lisa.get_grade())
print(bart.get_grade())
lisa.age = 18
print(lisa.age)
#print(bart.age)
'''
'''
kenw = student('wang dapei',99)
print(kenw.get_name)
print(kenw.get_score)
print(kenw.get_name())
print(kenw.get_score())
'''

'''
kenw = student('wang dapei',99)
print(kenw.get_score())
kenw.set_score(43)
print(kenw.get_score())
#kenw.set_score(101)
'''

'''
kenw = student('wang dapei',99)
print(kenw._student__name)
'''

'''
kenw = student('wang dapei',99)
print(kenw.get_name())
kenw.__name = 'xing yani'
print(kenw.__name)
print(kenw.get_name())
'''

bart = student('dapei','73','male')
if bart.get_gender() != 'male':
    print('测试失败!')
else:
    bart.set_gender('female')
    if bart.get_gender() != 'female':
        print('测试失败!')
    else:
        print('测试成功!')













