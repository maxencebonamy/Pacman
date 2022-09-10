from os import listdir
from os.path import isfile, join


PATH = "res/img/map/"

TILES = []

for directory in {"", "center_cell/", "walls/"}:
    TILES += [f"{directory}{f[:-4]}" for f in listdir(PATH + directory) if isfile(join(PATH + directory, f))]
