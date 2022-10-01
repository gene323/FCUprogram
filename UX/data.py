import random

with open('data.txt', 'w') as f:
    for i in range(40):
        w = random.randint(10, 500)
        h = random.uniform(1, 2.2);
        f.write(f"{i}\n{w}\n{h}\n")

    f.write(f"-9\n")
