import pytest
from fuel import convert , gauge


def main():
    test_convert()
    test_gauge()


def test_convert():
    assert convert('1/2') == 50
    assert convert('1/4') == 25
    assert convert('1/50') == 2
    assert convert('95/100') == 95

    with pytest.raises(ValueError):
        convert('a/b')

    with pytest.raises(ZeroDivisionError):
        convert('2/0')



def test_gauge():
    assert gauge(50) == '50%'
    assert gauge(1) == 'E'
    assert gauge(99) == 'F'



if __name__ == '__main__':
    main()
