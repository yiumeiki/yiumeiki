import validators

def main():
    print(is_valid(input("What's your email address? ")))

def is_valid(str):
    if validators.email(str):
        return "Valid"
    else:
        return "Invalid"

if __name__ == "__main__":
    main()
