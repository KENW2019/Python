'''
class student(object):
    def __init__(self,x,y):
        self.name = x
        self.score = y

    def print_score(self):
        print('%s: %s' % (self.name, self.score))

    def get_grade(self):
        if self.score >= 90:
            return 'A'
        elif self.score >= 60:
            return 'B'
        else:
            return 'C'
'''


class student(object):
    class_name = 'this class type for sutdent'
    class_atrribute_count = 0

    def __init__(self, x, y, z):
        self.__name = x
        self.__score = y
        self.__gender = z
        student.class_atrribute_count += 1

    def print_score(self):
        print('%s: %s' % (self.__name, self.__score))

    def get_grade(self):
        if self.__score >= 90:
            return 'A'
        elif self.__score >= 60:
            return 'B'
        else:
            return 'C'
    
    def get_name(self):
        return self.__name
    
    def get_score(self):
        return self.__score

    def set_score(self, int_latestValue):
        if 0 <= int_latestValue <= 100:
            self.__score = int_latestValue
        else:
            raise ValueError('bad score')

    def get_gender(self):
        return self.__gender
    
    def set_gender(self, str_gender):
        self.__gender = str_gender

