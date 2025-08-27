'''
Demonstrates basic error handling in Python with try-except blocks.
'''
def main():
    # Here, we try division by zero, which will raise an exception.
    print("1. Division by zero:")
    try:
        a = 10
        b = 0
        c = a / b
        print("Result =", c)
    except ZeroDivisionError as e:
        print("Caught ZeroDivisionError:", e)

    # Here, we access an out-of-bounds index, which will raise an exception.
    print("\n2. Index out-of-bounds:")
    lst = [1, 2, 3]
    try:
        print(lst[5])
    except IndexError as e:
        print("Caught IndexError:", e)

    # Here, we try to access an attribute of a None object, which will raise an exception.
    print("\n3. Null reference (None) access:")
    try:
        # A None object does not have attributes, so this will raise an AttributeError when we try to access one.
        ptr = None
        # This will raise an AttributeError, since 'NoneType' object has no attribute 'value'
        ptr.value = 42
    except AttributeError as e:
        print("Caught AttributeError:", e)

if __name__ == "__main__":
    main()
