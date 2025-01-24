import re

def main():
    print(convert(input("Hours: ")))

def error_check(time_str):
    match = re.match(r"(\d{1,2})(?::(\d{2}))?\s(AM|PM)", time_str)
    if not match:
        raise ValueError

    hour, minute, meridian = match.groups()
    hour = int(hour)
    minute = int(minute) if minute else 0

    if not (1 <= hour <= 12):
        raise ValueError
    if not (0 <= minute < 60):
        raise ValueError

    if meridian == "AM":
        if hour == 12:
            hour = 0
    else:
        if hour != 12:
            hour += 12

    return hour, minute


def convert(s):
    time_pattern = r"(\d{1,2})(?::(\d{2}))?\s(AM|PM)\s+to\s+(\d{1,2})(?::(\d{2}))?\s(AM|PM)"
    match = re.match(time_pattern, s)

    if not match:
        raise ValueError("Invalid time format")

    start_str = match.group(1) + (":" + match.group(2) if match.group(2) else "") + " " + match.group(3)
    end_str = match.group(4) + (":" + match.group(5) if match.group(5) else "") + " " + match.group(6)

    start_hour, start_minute = error_check(start_str)
    end_hour, end_minute = error_check(end_str)

    start_time = f"{start_hour:02}:{start_minute:02}"
    end_time = f"{end_hour:02}:{end_minute:02}"

    if start_hour > end_hour or (start_hour == end_hour and start_minute > end_minute):
        end_time = f"{(end_hour + 24) % 24:02}:{end_minute:02}"

    return f"{start_time} to {end_time}"

if __name__ == "__main__":
    main()
