def main():
    height = input("Height: ")
    try:
        height = int(height)
    except:
        # error
        return main()
    if height > 8 or height < 1:
        return main()
    height = int(height)
    for i in range(height):
        for j in range(height - 1 - i):
            print(" ", end="")
        for z in range(1 + i):
            print("#", end="")
        print()


main()