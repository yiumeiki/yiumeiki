from plates import is_valid

def test_digi():
    assert is_valid("22") == False
    assert is_valid("AA22A") == False
    assert is_valid("AA022") == False
    assert is_valid("AA22") == True

def test_alpha():
    assert is_valid("AAAAAAA") == False
    assert is_valid("A") == False
    assert is_valid("AA.A") == False
    assert is_valid("AA A") == False
    assert is_valid("AAAAA") == True
