from twttr import shorten

def test_shorten():
    assert shorten('apple') == 'ppl'
    assert shorten('banana') == 'bnn'
    assert shorten('CAT') == 'CT'
    assert shorten('DOG') == 'DG'
    assert shorten(',!.') == ',!.'
    assert shorten('123a') == '123'
