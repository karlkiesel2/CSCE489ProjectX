def main():
    lines = []
    print("Enter lines of text. Type 'print' to display all entries.")

    while True:
        user_input = input()
        if user_input == "print":
            print("Stored lines:")
            for line in lines:
                print(line)
            break
        lines.append(user_input)

if __name__ == "__main__":
    main()
