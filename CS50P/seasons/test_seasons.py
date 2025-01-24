import pytest
from seasons import get_difference, get_date
from datetime import date

def test_input():
    assert get_difference(date(1999, 5, 18)) == "Thirteen million, four hundred eighty-seven thousand forty minutes"
    assert get_difference(date(2010, 1, 1)) == "Seven million, eight hundred ninety-eight thousand, four hundred minutes"
