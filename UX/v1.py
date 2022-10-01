#!/usr/bin/python3
w = float(input('Please input the weight(ex 60): '))
while w <= 0.0 or w >= 1000.0:
    print("Wrong!")
    w = float(input('Please input the weight(ex 60): '))

h = float(input('Please input the height(ex. 1.87): '))
while h <= 0.0 or h >= 2.6:
    print("Wrong!")
    h = float(input('Please input the height(ex. 1.87): '))

bmi = w/(h*h)
print("your BMI is %.2f" % (bmi))
