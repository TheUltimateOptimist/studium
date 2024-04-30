count = 0
for i in range(128):
    ones_count = 0
    for value in bin(i):
        if value == "1":
            ones_count += 1
    if ones_count >= 2:
        count += 1
print(count)