
import pickle


d = dict(name='bob',age=20,score=80)

f = open('/home/k/LinuxShare/Python/liaoxuefeng_python/io_test/dump.txt', 'wb')

pickle.dump(d,f)

f.close()




f = open('/home/k/LinuxShare/Python/liaoxuefeng_python/io_test/dump.txt', 'rb')
d = pickle.load(f)
f.close()
print(d)

