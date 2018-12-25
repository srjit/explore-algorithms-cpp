

__author__ = "Sreejith Sreekumar"
__email__ = "sreekumar.s@husky.neu.edu"
__version__ = "0.0.1"



entity_map = {'a':1, 'b':5}


entity_vocab = ['a','b','c','d']


tmp = ['a','b']

labels = [0 if x in tmp  for x in entity_map else 1]






