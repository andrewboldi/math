months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
# add one for leap year too 
start = [1, 1, 2022]
end = [12, 31, 2030]

count = 0

for year in range(start[2], end[2] + 1): # every year
    for month in range(1, 12 + 1): # every month
        for day in range(1, months[month - 1] + 1):
            if day * month == int(str(year)[-2:]):
                count += 1
                print(month, day, int(str(year)[-2:]))

print(count)
        
