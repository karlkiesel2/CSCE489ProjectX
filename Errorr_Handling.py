def main():
    print("1. Division by zero:")
    try:
        a = 10
        b = 0
        c = a / b
        print("Result =", c)
    except ZeroDivisionError as e:
        print("Caught ZeroDivisionError:", e)

    print("\n2. Index out-of-bounds:")
    lst = [1, 2, 3]
    try:
        print(lst[5])
    except IndexError as e:
        print("Caught IndexError:", e)

    print("\n3. Null reference (None) access:")
    try:
        ptr = None
        ptr.value = 42  # AttributeError
    except AttributeError as e:
        print("Caught AttributeError:", e)

if __name__ == "__main__":
    main()
