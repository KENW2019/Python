#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
age = input('hi,please input your age -->:')

if int(age) >= 18:
    print('adult')
else:
    print('teenager')
'''
print('中文测试')

a = 'ABC'
b = a
a = 'XYZ'
print(b)


c = 5//2;
d = 5%2;
e = 10/3;

print(c,d,e)

len('ABC')
len('中文')

b'\xe4\xb8\xad\xff'.decode('utf-8', errors='ignore')

len('中文'.encode('utf-8'))


'Hello, %s' % 'world'

'hi, %s, you have $%d.' % ('michael',1000)

print('%010d-%02d' % (3, 1))
print('%.2f' % 3.1415926)

'Age: %s. Gender: %s' % (25,True)

s1 = 72
s2 = 85
r = ((85-72)/72)*100
print('%.1f%%' % r)