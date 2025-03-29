def factorial():
    num1 = int(input("Enter starting number: "))
    num2 = int(input("Enter ending number: "))

    factorial = 1
    for h in range(num1, num2 + 1):
        factorial *= h
        print(f"{h}: {factorial}", file=open(f"{num1}-{num2}.txt", "a"))


if __name__ == "__main__":
    factorial()
"""
        if h < 0:
            print("Sorry, factorial does not exist for negative numbers")
        elif h == 0:
            print("The factorial of 0 is 1")
        else:
            factorial *= h
"""
#        print(str(factorial)[:1] + "." + str(factorial)[1:22] + r"e+" + str(len(str(factorial)) - 1) + r",       /* " + str(h) + r"! */")
