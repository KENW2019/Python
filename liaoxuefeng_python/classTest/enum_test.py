from enum_class import Weekday
from enum_class import Student
from enum_class import Gender


'''
day1 = Weekday.Mon

print(day1)

print(Weekday.Tue)

print(Weekday['Tue'])

print(Weekday.Tue.value)

print(day1 == Weekday.Tue)

Weekday(7)
'''


bart = Student('Bart', Gender.Male)
if bart.gender == Gender.Male:
    print('测试通过!')
else:
    print('测试失败!')

