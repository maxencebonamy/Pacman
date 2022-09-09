import pygame
from pygame.math import Vector2
import sys


# CONSTS
GRID_SIZE = Vector2(28, 31)
CELL_SIZE = 32


pygame.init()

window = pygame.display.set_mode(GRID_SIZE * CELL_SIZE)
pygame.display.set_caption("Pacman Map Maker")


while True:

    pygame.display.update()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
