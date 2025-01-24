from um import count
import pytest

def test_count():
    assert count("um...") == 1
    assert count("UM...") == 1
    assert count("..um..um..") == 2
    assert count("yummy") == 0
