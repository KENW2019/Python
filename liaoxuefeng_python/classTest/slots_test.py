
import slots_class


s = slots_class.Student()

s.name = 'dapei'
s.age = 23

s.score = 78

print(s.name,s.age,s.score)

class graduateStudent(slots_class.Student):
    pass

g = graduateStudent()
g.score = 9999
g.name = 'yani'
print(g.score,g.name)


