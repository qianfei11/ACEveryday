import functools

def log(text):
    def decorator(func):
        # @functools.wraps(func)
        def wrapper():
            print("{} {}():".format(text, func.__name__))
            return func()
        return wrapper
    return decorator

@log("execute")
def now():
    print("2018-4-22")

now()
print(now.__name__)
