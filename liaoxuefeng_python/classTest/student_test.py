import student

'''
s = student.student('dapei',89,'male')

print(s.class_name)

print(student.student.class_name)

s.class_name = 'yani'

print(s.class_name)

print(student.student.class_name)

del s.class_name

print(s.class_name)

print(student.student.class_atrribute_count)
'''

if student.student.class_atrribute_count != 0:
    print('测试失败!')
else:
    bart = student.student('Bart',88,'male')
    if student.student.class_atrribute_count != 1:
        print('测试失败!')
    else:
        lisa = student.student('lisa',77,'female')
        if student.student.class_atrribute_count != 2:
            print('测试失败!')
        else:
            print('students:', student.student.class_atrribute_count)
            print('测试通过!')


