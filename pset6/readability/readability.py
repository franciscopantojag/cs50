def main():
    text = input("Text: ")
    text = text.strip()
    letters = 0
    spaces = 0
    sentences = 0
    for character in text:
        if character.isalpha():
            letters += 1
        if character.isspace():
            spaces += 1
        if character == "." or character == "!" or character == "?":
            sentences += 1
    words = spaces + 1
    L = letters * 100 / words
    S = sentences * 100 / words
    result = round(0.0588 * L - 0.296 * S - 15.8)
    if(result >= 16):
        print(f"Grade 16+")
        return 0
    elif(result < 1):
        print(f"Before Grade 1")
        return 0
    print(f"Grade {result}")


if __name__ == "__main__":
    main()