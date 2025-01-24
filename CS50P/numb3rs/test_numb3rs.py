from numb3rs import validate

def test_format():
    assert validate(r"1.2.3.4.5.6") == False
    assert validate(r"1") == False
    assert validate(r"1.2.3") == False
    assert validate(r"255/255/255/255") == False
    assert validate(r"0.0.0.0") == True
    assert validate(r"255.255.255.255") == True

def test_input():
    assert validate(r"256.0.0.0") == False
    assert validate(r"255.256.0.0") == False
    assert validate(r"255.255.256.0") == False
    assert validate(r"255.255.255.256") == False
    assert validate(r"255.255.255.255") == True
    assert validate(r"cat") == False
