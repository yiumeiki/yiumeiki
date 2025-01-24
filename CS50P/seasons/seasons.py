from datetime import date
import inflect
import sys

p = inflect.engine()

def main():
    dob = input("Date of Birth: ")
    formatted_date = get_date(dob)
    result = get_difference(formatted_date)
    print(result)

def get_date(dob):
    try:
        formatted_date = date.fromisoformat(dob)
        return formatted_date
    except ValueError:
        sys.exit("Invalid date")

def get_difference(formatted_date):
    today = date.today()
    days_to_min = today - formatted_date
    return p.number_to_words(days_to_min.days * 24 * 60, andword="").capitalize() + " minutes"


if __name__ == "__main__":
    main()
