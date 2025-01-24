name = input("File name: ").strip().split(".")

if len(name) > 1:
    extension = name[-1].lower()

    if extension in ["jpg", "jpeg", "gif", "png"]:
        if extension in ["jpg", "jpeg"]:
            print("image/jpeg")
        else:
            print(f"image/{extension}")
    elif extension in ["pdf", "zip"]:
        print(f"application/{extension}")
    elif extension == "txt":
        print("text/plain")
    else:
        print("application/octet-stream")
else:
    print("application/octet-stream")

