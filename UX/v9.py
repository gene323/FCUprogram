#!/usr/bin/python3
def red():
    print("\033[31m", end='');
def reset():
    print("\033[0m", end='');
def green():
    print("\033[32m", end='');

def input_info():
    print('======================')
    print("\nPlease input weight and height, press \"-9\" to stop")
    while True:
        n = str(input('please input the name: '))
        if (n == '-9'):
            break
        while True:
            try:
                w = float(input('Please input the weight (kg): '))
            except ValueError:
                print('Input should be a value, please re-input ')
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
            break;

        bmi = round(w/(h**2), 1)
        bmis[n] = bmi
    for k,v in bmis.items():
        if (v>= 24):
            over_w[k] = v
        elif (v<= 18.5):
            under_w[k] = v
        else:
            normal[k] = v


def print_over_weight():
    if(over_w):
        print('======================')
        red()
        print('over weight')
        for k,v in over_w.items():
            print('The BMI of {} is {}'.format(k,v))
        print(f'over weight range people: {len(over_w)}')
        reset();

def print_normal_weight():
    if(normal):
        print('======================')
        print('normal');
        for k,v in normal.items():
            print('The BMI of {} is {}'.format(k, v))
        print(f'normal range people: {len(normal)}')

def print_under_weight():
    if(under_w):
        print('======================')
        green()
        print('under weight')
        for k,v in under_w.items():
            print('The BMI of {} is {}'.format(k,v))
        print(f'under weight range people: {len(under_w)}')
        reset();

def print_bmi():
    print_normal_weight();
    print_over_weight();
    print_under_weight();

bmis = {}
normal, over_w, under_w = {}, {}, {}
print("press 1 to calculate BMI")
print("press 2 to print normal range BMI")
print("press 3 to print over weight range BMI")
print("press 4 to print under weight range BMI")
print("press 5 to print all range BMI")
print("press -9 to exit")
while True:
    mode = int(input("press: "))
    if(mode == 1):
        input_info()
    elif(mode == 2):
        print_normal_weight()
    elif(mode == 3):
        print_over_weight()
    elif(mode == 4):
        print_under_weight()
    elif(mode == 5):
        print_bmi()
    elif(mode == -9):
        break
    else:
        print("press 1 to calculate BMI")
        print("press 2 to print normal range BMI")
        print("press 3 to print over weight range BMI")
        print("press 4 to print under weight range BMI")
        print("press 5 to print all range BMI")
        print("press -9 to exit")
        print("Error!")

