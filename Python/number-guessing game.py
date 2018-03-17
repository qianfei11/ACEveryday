#!/usr/bin/python
import random

num = random.randint(0, 1000)
print("Let's start playing the number guessing game!\n")
time = 0

while True:
    try:
        guess = eval((input("Please enter a number between 1~1000:\n")))
    except SyntaxError as e:
        print("Please enter a number!\n")
        continue
    time += 1
    if guess < num:
        print("The num is bigger than ", guess, "\n")
    elif guess > num:
        print("The num is smaller than ", guess, "\n")
    else:
        print("Wow! How clever you are! You get the right num!\n")
        print("The time you have guessed:", time, "\n")
        break
