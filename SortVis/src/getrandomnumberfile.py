import random

f = open("testfile.txt", "w")

for i in range(500, 1, -1):
    f.write(f"{random.randint(-1000,1000)}\n")

f.close()
