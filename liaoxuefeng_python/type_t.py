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
