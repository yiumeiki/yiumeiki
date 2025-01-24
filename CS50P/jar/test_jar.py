from jar import Jar
import pytest

def test_init():
    jar = Jar()


def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"


def test_deposit():
    jar = Jar()
    jar.deposit(3)
    assert jar.size == 3
    with pytest.raises(ValueError):
        jar.deposit(13)
    with pytest.raises(ValueError):
        jar.deposit(-1)


def test_withdraw():
    jar = Jar()
    jar.deposit(12)
    jar.withdraw(10)
    assert jar.size == 2
    with pytest.raises(ValueError):
        jar.withdraw(13)
    with pytest.raises(ValueError):
        jar.withdraw(-1)
