import re
import sys

def main():
    print(parse(input("HTML: ")))


def parse(s):
    if re.search(r"<iframe(.)*><\/iframe>", s):
        match = re.search(r"(http(s)*:\/\/(www\.)*youtube\.com\/embed\/)([a-z_A-Z_0-9]+)", s)

        if match:
            video_id = match.group(4)
            return "https://youtu.be/" + video_id
        else:
            return "None"

if __name__ == "__main__":
    main()
