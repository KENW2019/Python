
file_handler = open('/home/k/LinuxShare/Python/liaoxuefeng_python/io_test/test.txt', 'r')

'''
str2 = file_handler.read()

print(str2)
'''

for line in file_handler.readlines():
    print(line.strip())


file_handler.close()


