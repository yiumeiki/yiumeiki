
def main():
    jar = Jar()
    print(jar)
    jar.deposit(10)
    print(jar)
    jar.withdraw(8)
    print(jar)


class Jar:

    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪" * self.size;

    def deposit(self, n):
        if self.size + n <= self.capacity and n >= 0:
            self.size += n
        else:
            raise ValueError

    def withdraw(self, n):
        if self.size - n >= 0 and n >= 0:
            self.size -= n
        else:
            raise ValueError

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        if capacity < 1:
            raise ValueError
        else:
            self._capacity = capacity

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, size):
        if size > self.capacity:
            raise ValueError
        else:
            self._size = size



if __name__ == "__main__":
    main()
