'''
classmates = ['Michael', 'Bob', 'Tracy']
len(classmates)
classmates[0]

classmates.append('adam')

classmates.insert(1, 'jack')

L = ['Apple', 123, True]

classmates = ('Michael', 'Bob', 'Tracy')

L = [
    ['Apple', 'Google', 'Microsoft'],
    ['Java', 'Python', 'Ruby', 'PHP'],
    ['Adam', 'Bart', 'Lisa']
]

print(L[0][0])

age = 17
if age >= 18:
    print('your age is',age)
else:
    print('teenager')
    

age = 3
if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')


age = 20
if age >= 6:
    print('teenager')
elif age >= 18:
    print(age)
else:
    print('kid')
'''


height = 1.7
weight = 75
bmi = weight/(height*height)
if bmi < 18.5:
    print("too light")
elif bmi > 18.5 and bmi < 25:
    print("normal")
else:
    print("fat")


