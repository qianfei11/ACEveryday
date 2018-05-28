class Student(object):
    def __init__(self, name, age, scores=[]):
        self.name = name
        self.age = age
        self.scores = scores
    def get_name(self):
        print(self.name)
    def get_age(self):
        print(self.age)
    def get_score(self):
        print(max(self.scores))

if __name__ == '__main__':
    zm = Student('zhangming', 20, [69, 88, 100])
    zm.get_name()
    zm.get_age()
    zm.get_score()