# Error Handling - Any unexpected outcome
# Well prepared to handle the Exception and continue the program
print("Hello World")
try:
    print(1/0) # ZeroDivisionError: division by zero
except ZeroDivisionError:
    print("Divided by zero")
else:
    print("No exception")
finally:
    print("This line will finally be printed")
print("This line will be printed")    

try:
    f=open("test.txt",'w')
    f.write("Test write this")
except:
    print("Error in writing to the file")
else:
    print("File write was a success")
finally:
    print("Finally always executes")
# Ask user to enter number
# If user enters a string, ask to enter a number
# If user enters a number, print the square of the number
while True:
    try:
        number=int(input("Please enter a number: "))
    except:
        print("You did not enter a number")
        continue
    else:
        number=number**2
        print("Thank you, your number squared is: ",number)
        break
    finally:
        print("Finally block executed")

class InvalidAgeException(Exception):
    pass
def check_age(age):
    if age<18:
        raise InvalidAgeException("Age is less than 18")
    else:
        print("Valid age")
try:
    check_age(17)
except InvalidAgeException as e:
    print(e)
else:
    print("All good")
finally:
    print("Finally block executed")
        
