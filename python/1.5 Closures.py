# What are closure - A closure is a function object that remembers values in enclosing scopes even if they are not present in memory.
def greet(name):
    def get_message():
        return 'Hello ' + name 
    
    result = get_message()
    return result
greeter = greet('John')
print(greeter)

def calculate():
    n=1
    def add():
        nonlocal n
        n+=2
        return n
    return add
print(calculate()())
print(calculate()())
print(calculate()())

inner = calculate()
print(inner())
print(inner())

def add(n):
    def adder(x):
        return n+x
    return adder
a1 = add(5)(3)
print(a1)

#what are decorators - A decorator takes in a function, adds some functionality and returns it.
def make_pretty(func):
    def inner():
        print("I got decorated")
        func()
    return inner
def ordinary():
    print("I am ordinary")
ordinary()
pretty = make_pretty(ordinary)
pretty()

@make_pretty
def ordinary2():
    print("I am ordinary 2")

ordinary2()