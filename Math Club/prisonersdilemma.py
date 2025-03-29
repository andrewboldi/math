import random
while True:
    simulate_inp = input("Simulate (S) or interactive (I): ")
    if simulate_inp == "S" or simulate_inp == "s":
        simulate = True
        dev = False
        break
    elif simulate_inp == "I" or simulate_inp == "i":
        simulate = False
        dev = False
        break
    elif simulate_inp == "D" or simulate_inp == "d":
        simulate = False
        dev = True
        break
    else:
        pass

inputs = []
response = [random.choice([0, 1])]
bot_score = 0
user_score = 0
i = 0

if simulate:
    streak = 1 # defect only probably best approach
else:
    streak = 3

for j in range(0, 1000):
    if simulate:
        inp = random.choice(["C", "D"])
    else:
        inp = input("Cooperate (C) or Defect (D): ")


    if inp == "C" or inp == "c":
        inputs.insert(0, 1)
    elif inp == "D" or inp == "d":
        inputs.insert(0, 0)
    else:
        continue

    if i >= 1:
        response.insert(0, inputs[1])
    if i >= 3:
        if inputs[0:streak] == [1] * streak:
            response[0] = 0
        if not simulate:
            if i % random.choice([4, 5, 6, 7, 8, 9, 10]) == 0:
                response[0] = random.choice([0, 1])
        if inputs[0:streak] == [0] * streak:
            response[0] = 0

    if not simulate:
        if response[0]:
            print(f"\nResponse: Cooperate")
        else:
            print(f"\nResponse: Defect")


    if inputs[0] and not response[0]:
        user_score += 10
    elif not inputs[0] and response[0]:
        bot_score += 10
    elif inputs[0] and response[0]:
        user_score += 2
        bot_score += 2
    elif not inputs[0] and not response[0]:
        user_score += 5
        bot_score += 5
    else:
        print("wat")

    if not simulate:
        print(f"YOU are getting {user_score} years in jail while the BOT is getting {bot_score} years in jail!\n")
    if dev:
        print(f"User History: {inputs}")
        print(f"Bot History:  {response}\n")

    i += 1
if simulate:
    print(f"YOU are getting {user_score} years in jail while the BOT is getting {bot_score} years in jail!")
