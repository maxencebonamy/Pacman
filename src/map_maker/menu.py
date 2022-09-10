import pygame

from tiles import TILES
from config import *
import math


class Menu:

    def __init__(self, x_pos):
        self.size = Vector2(math.ceil(len(TILES) / GRID_SIZE.y), GRID_SIZE.y)
        self.x_pos = x_pos

        self.images = {
            tile: pygame.image.load(f"res/img/map/{tile}.png") for tile in TILES
        }

        for name, image in self.images.items():
            self.images[name] = pygame.transform.scale(image, (CELL_SIZE, CELL_SIZE))

    def display(self, window):
        x, y = self.x_pos, 0
        for image in self.images.values():
            window.blit(image, (x, y, CELL_SIZE, CELL_SIZE))
            y += CELL_SIZE
            if y >= self.size.y * CELL_SIZE:
                y = 0
                x += CELL_SIZE

    def get_new_element(self, mouse_position):
        x, y = self.x_pos, 0
        for name in self.images.keys():
            if pygame.Rect(x, y, CELL_SIZE, CELL_SIZE).collidepoint(mouse_position):
                return name
            y += CELL_SIZE
            if y >= self.size.y * CELL_SIZE:
                y = 0
                x += CELL_SIZE

        return None
