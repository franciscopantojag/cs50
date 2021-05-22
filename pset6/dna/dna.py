from sys import argv, exit
import csv


def main():
    if len(argv) != 3:
        print(f"Bad usage, there should be 2 argv, you have {argv}")
        return 1
    with open(argv[1], "r") as file:
        reader = list(csv.reader(file))
        reader[0].remove("name")
        STRS = reader[0]
    with open(argv[2], "r") as sequence:
        data = sequence.read()
    valuelist = []
    for q in range(len(STRS)):
        maxcounter = 0
        counter = 0
        position = 0
        previouspos = 0
        while position < len(data):
            position = data.find(STRS[q], position)
            if position == -1:
                counter = 0
                break
            elif (position != -1) and previouspos == 0:
                counter += 1
                maxcounter = counter
                previouspos = position
            elif (position != -1) and ((position - len(STRS[q])) == previouspos):
                counter += 1
                previouspos = position
                if maxcounter < counter:
                    maxcounter = counter
            elif (position != -1) and ((position - len(STRS[q])) != previouspos):
                counter = 1
                previouspos = position
                if maxcounter < counter:
                    maxcounter = counter
            position += 1
        valuelist.append(maxcounter)

    valuelist = list(map(str, valuelist))
    cleaned = list(reader)
    cleaned.pop(0)
    for person in cleaned:
        if person[1:] == valuelist:
            print(f"{person[0]}")
            break
        elif person == cleaned[-1]:
            print("No match")
    return 0


if __name__ == "__main__":
    main()