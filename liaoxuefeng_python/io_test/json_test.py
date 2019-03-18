
import json

'''
d = dict(name = 'bob',age = 20,score = 80)

f = open('/home/k/LinuxShare/Python/liaoxuefeng_python/io_test/dump.txt', 'w')

json.dump(d,f)

f.close()
'''

g = open('/home/k/LinuxShare/Python/liaoxuefeng_python/io_test/dump.txt', 'r')

h = json.load(g)

print(h)

g.close()