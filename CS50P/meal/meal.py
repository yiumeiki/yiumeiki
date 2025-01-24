def main():
    time = input("What time is it? ")
    hour = convert(time)
    if 7 <= hour <= 8:
        print("breakfast time")
    elif 12 <= hour <= 13:
        print("lunch time")
    elif 18 <= hour <= 19:
        print("dinner time")
    else:
        return

def convert(time):
    if len(time.split(" ")) != 2:
        hours, minutes = int(time.split(":")[0])
        minutes = int(time.split(":")[1])
        return hours + minutes / 60
    else:
        if time.split(" ")[-1] == "a.m.":
            hours = int(time.split(":")[0])
        else:
            hours = int(time.split(":")[0]) + 12
        minutes = int(time.split(" ")[0].split(":")[1])
        return hours + minutes / 60


if __name__ == "__main__":
    main()
