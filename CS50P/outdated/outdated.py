month = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]

while True:
    date = input("Date: ").strip()
    if date[0].isalpha() and len(date.split(" ")) == 3:
        list = date.split(" ")
        m = str(month.index(list[0]) + 1)
        if list[1][-1] != ",":
            continue
        d = list[1][:-1]
        if int(d) > 31 or list[0] not in month:
            continue
        y = list[2]
        break
    elif len(date.split("/")) == 3 and date.split("/")[0].isdigit():
        list = date.split("/")
        m = list[0]
        d = list[1]
        if int(d) > 31 or int(m) > 12:
            continue
        y = list[2]
        break
    else:
        pass

print(y + "-" + m.zfill(2) + "-" + d.zfill(2))
