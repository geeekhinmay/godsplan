def main() -> None:
    try:
        number = int(input("Enter an integer: "))
    except ValueError:
        print("Please enter a valid integer.")
        return

    if number % 2 == 0:
        print(f"{number} is even.")
    else:
        print(f"{number} is odd.")


if __name__ == "__main__":
    main()
