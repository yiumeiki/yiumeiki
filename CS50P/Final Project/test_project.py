import pytest
from project import calculate_score, compare, deal_card
import colorama
from colorama import Fore, Style
colorama.init(autoreset=True)


def test_calculate_score():
    assert calculate_score([11,1,10]) == 12
    assert calculate_score([3,7,11]) == 21
    assert calculate_score([7,7,8]) == 22

def test_compare():
    assert compare(20, 10) == Style.BRIGHT + Fore.GREEN + "You win!!"
    assert compare(10, 20) == Fore.RED + "You lose;("
    assert compare(22, 22) == Style.BRIGHT + Fore.RED + "Both bust... You lose..."
    assert compare(20, 20) == Style.BRIGHT + Fore.BLUE + "Draw"

def test_deal_card():
    card = deal_card()
    assert card in [11, 2, 3, 4, 5, 6, 7, 8, 9, 10]
