# Generator function allows us to write a function that can send back a value and then later resume to pick up where it left off. 
# This type of function is a generator in Python, allowing us to generate a sequence of values over time. The main difference in syntax will be the use of a yield statement.
def gensquare(n):
    for i in range(n):
        yield i**2

for i in gensquare(5):
    print(i)

print('=========')

def genfibo(n):
    a = 1
    b = 1
    for i in range(n):
        yield a
        a,b = b,a+b

for i in genfibo(10):
    print(i)

# next() and iter() built-in functions
    
fib = genfibo(5)
print(next(fib))
print(next(fib))
print(next(fib))