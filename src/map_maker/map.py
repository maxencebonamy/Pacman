import pygame.draw

from config import *


class Map:

    def __init__(self, images, default_name, save=None):
        self.images = images
        self.current_element = default_name

        self.map = []

        if save is None:
            for y in range(int(GRID_SIZE.y)):
                self.map.append([default_name for _ in range(int(GRID_SIZE.x))])
        else:
            with open(f"res/map/{save}.txt", 'r', encoding="utf-8") as file:
                for line in file:
                    self.map.append(line.replace('\n', '').split(';'))

    def display(self, window):
        for y in range(int(GRID_SIZE.y)):
            for x in range(int(GRID_SIZE.x)):
                window.blit(self.images[self.map[y][x]], (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE))

        for x in range(int(GRID_SIZE.x + 1)):
            pygame.draw.line(window, (255, 255, 255), (x * CELL_SIZE, 0), (x * CELL_SIZE, GRID_SIZE.y * CELL_SIZE))

        for y in range(int(GRID_SIZE.y)):
            pygame.draw.line(window, (255, 255, 255), (0, y * CELL_SIZE), (GRID_SIZE.x * CELL_SIZE, y * CELL_SIZE))

    def save(self, path):
        with open(path, 'w', encoding="utf-8") as file:
            for y in range(int(GRID_SIZE.y)):
                for x in range(int(GRID_SIZE.x)):
                    file.write(self.map[y][x])
                    if x != GRID_SIZE.x - 1:
                        file.write(';')
                file.write('\n')
