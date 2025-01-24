from bank import value

def test_lower():
    assert value("hello")==0
    assert value("hello123?")==0
    assert value("how's your day")==20
    assert value("yo whats up?")==100

def test_caps():
    assert value("Hello")==0
    assert value("Hello123?")==0
    assert value("How's your day")==20
    assert value("Yo Whats up?")==100
