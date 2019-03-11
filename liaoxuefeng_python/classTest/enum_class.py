
from enum import Enum,unique

@unique
class Weekday(Enum):
    Sun = 0 # Sun的value被设定为0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6


@unique
class Gender(Enum):
    Male = 0
    Female = 1



class Student(object):
    def __init__(self,name,gender):
        self._name = name
        self._gender = gender
    
    @property
    def gender(self):
        return self._gender

    @gender.setter
    def gender(self,gender):
        self._gender = gender

