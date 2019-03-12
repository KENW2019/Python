
''' variable para V1 '''
'''
def calc(numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum
'''


''' variable para V2 '''
def calc(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum
