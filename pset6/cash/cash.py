from cs50 import get_float
from math import floor


def main():
    changeOwed = get_float("Change owed: ")
    if changeOwed < 0:
        return main()
    quarters = floor(changeOwed / 0.25)
    dimes = floor(round(changeOwed % 0.25, 2) / 0.1)
    nickels = floor(round(round(changeOwed % 0.25, 2) % 0.1, 2) / 0.05)
    pennies = floor(round(round(round(changeOwed % 0.25, 2) %
                                0.1, 2) % 0.05, 2) / 0.01)
    print(quarters + dimes + nickels + pennies)


if __name__ == "__main__":
    main()