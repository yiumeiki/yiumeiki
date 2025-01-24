name = []
i = 0
while True:
    try:
        name.append(input("Name: "))

    except EOFError:
        print("Adieu, adieu, to ", end = "")
        match len(name):
            case 1:
                print(name[i])
            case 2:
                print(name[i] , "and", name[i + 1])
            case _:
                for i in range(len(name) - 2):
                    print(name[i] + ", " ,end = "")
                print(name[i + 1] + ", and", name[i + 2])
        break
