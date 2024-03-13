#!/usr/bin/env python3

class Test(object):

    def __init__(self, subject_name="", correct_answers=[], pasing_mark=""):
        self.subject_name = subject_name
        self.correct_answers = correct_answers
        self.pasing_mark = int(pasing_mark[:-1])

class Student(object):

    def __init__(self, name=""):
        self.name = name

    def take_test(self, paper, list=[]):
        points = 0
        for i in list:
            if i in paper.correct_answers:
                points +=1
        grade = points / len(paper.correct_answers) * 100
        #print(grade)

        if grade >= paper.pasing_mark:
            return "{} passed the {} test with the score {}%".format(self.name, paper.subject_name, grade)
        else:
            return "{} failed the {} test!".format(self.name, paper.subject_name)


paper1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
paper2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
paper3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')

stu1 = Student('Tom')
print(stu1.take_test(paper2, ['1C', '2C', '3D', '4A']))

stu2 = Student('John')
print(stu2.take_test(paper1, ['1B', '2C', '3A', '4A', '5B']))
