item = {}
value = 0
list = []

while True:
    try:
        key = input().upper()
        if key in item:
            value += 1
        else:
            value = 0
        item[key] = value + 1

    except EOFError:
        for keys in item.keys():
            list.append(keys)
        sort_list = list.sort()
        for key in list:
            print(item[key], key)
        break
