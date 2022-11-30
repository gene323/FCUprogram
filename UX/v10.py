#!/usr/bin/python3
class BMI():
    WHITE = '\033[37m'
    RED = '\033[31m'
    GREEN = '\033[32m'
    def __init__(self, name, h, w):
        self.h = h
        self.w = w
        self.bmi = round(w/(h**2), 1)
        self.name = name
        if self.bmi < 18.5:
            self.renderColor = BMI.GREEN
            self.TYPE = 'under weight'
        elif self.bmi <= 24.9:
            self.renderColor = BMI.WHITE
            self.TYPE = 'normal weight'
        else:
            self.renderColor = BMI.RED
            self.TYPE = 'over weight'
    def __str__(self):
        return '{}{}{}'.format(self.renderColor, self.bmi, '\033[0m')

def inputBMI():
    print('======================')
    print("\nPlease input weight and height, press \"-9\" to stop")
    while True:
        n = str(input('Please input the name: '))
        if (n == '-9'):
            break
        while True:
            try:
                w = float(input('Please input the weight (kg): '))
            except ValueError:
                print ('Input should be a value, please re-input ')
                continue
            if (w == -9):
                break
            elif (w>500 or w<10):
                print ('Weight should be in the range (10, 500), please re-input ')
                continue
            break;
        while True:
            try:
                h = float(input('Please input the height (m): '))
            except ValueError:
                print ('Input should be a value, please re-input ')
                continue
            if (h == -9):
                break
            elif (h>2.2 or h <1):
                print ('Height should be in the range (1, 2.2), please re-input ')
                continue
            break
        
        bmi.append(BMI(n, h, w))

def printBMI(bmi, color, type):
    sum = 0
    print('===={}{}{}===='.format(color, type, '\033[0m'))
    for i in bmi:
        if i.TYPE == type:
            print(f'The BMI of {i.name} is {i}')
            sum += 1
    if sum > 0:
        print('%s%s range people: %s%s\n' % (color, type, sum, '\033[0m'))

def printBMIBySort(func):
    tmp = eval(func)()
    for i in tmp:
        print(f'Name: {i.name}, Height: {i.h}, Weight: {i.w}, BMI: {i}')

def heightSort():
    return sorted(bmi, key=lambda x: x.h)

def weightSort():
    return sorted(bmi, key=lambda x: x.w)

def nameSort():
    return sorted(bmi, key=lambda x: x.name)

bmi = []

print("press 1 to calculate BMI")
print("press 2 to print normal range BMI")
print("press 3 to print over weight range BMI")
print("press 4 to print under weight range BMI")
print("press 5 to print all range BMI")
print("press 6 to print all range BMI by height order")
print("press 7 to print all range BMI by weight order")
print("Press 8 to print all range BMI by name order")
print("press -9 to exit")
while True:
    mode = int(input("press: "))
    if mode == 1:
        inputBMI()
    elif mode == 2:
        printBMI(bmi, BMI.WHITE, 'normal weight')
    elif mode == 3:
        printBMI(bmi, BMI.RED, 'over weight')
    elif mode == 4:
        printBMI(bmi, BMI.GREEN, 'under weight')
    elif mode == 5:
        printBMI(bmi, BMI.GREEN, 'under weight')
        printBMI(bmi, BMI.WHITE, 'normal weight')
        printBMI(bmi, BMI.RED, 'over weight')
    elif mode == 6:
        printBMIBySort('heightSort')
    elif mode == 7:
        printBMIBySort('weightSort')
    elif mode == 8:
        printBMIBySort('nameSort')
    elif mode == -9:
        break
    else:
        print("press 1 to calculate BMI")
        print("press 2 to print normal range BMI")
        print("press 3 to print over weight range BMI")
        print("press 4 to print under weight range BMI")
        print("press 5 to print all range BMI")
        print("press 6 to print all range BMI by height order")
        print("press 7 to print all range BMI by weight order")
        print("Press 8 to print all range BMI by name order")
        print("press -9 to exit")
        print("Error!")