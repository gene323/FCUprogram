#!/usr/bin/python3
print("Please input weight and height, press \"-9\" to stop")
bmis = {}

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
        break;


    bmi = round(w/(h**2), 1)
    bmis[n] = bmi

normal, over_w, under_w = {}, {}, {}

for k,v in bmis.items():
# print ('The BMI of {} is {}'.format(k, v))
    if (v>= 24):
        over_w[k] = v
    elif (v<= 18.5):
        under_w[k] = v
    else:
        normal[k] = v

    if (not over_w and not under_w):
        print ('Every one is good!!')

    if (over_w):
        print ('Overweight people, please Exercise ⚽️⚽️!')
for k,v in over_w.items():
    print ('The BMI of {} is {} '.format(k,v))
    print ()

if (under_w):
    print ('Under weight people, please Eat more 🍖🍖!')
for k,v in under_w.items():
    print ('The BMI of {} is {} '.format(k,v))
