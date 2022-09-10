import pygame
from pygame.math import Vector2
import sys
from config import *
from menu import Menu
from map import Map


selected_tile = 0


pygame.init()

menu = Menu((GRID_SIZE.x + 1) * CELL_SIZE)
grid_map = Map(menu.images, "void")
window_size = Vector2(GRID_SIZE.x + menu.size.x + 1, GRID_SIZE.y) * CELL_SIZE
window = pygame.display.set_mode(window_size)
pygame.display.set_caption("Pacman Map Maker")

is_clicking = False
while True:

    window.fill((0, 0, 0))

    menu.display(window)
    grid_map.display(window)

    pygame.display.update()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            grid_map.save("res/map/troll.txt")
            pygame.quit()
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN and event.button == pygame.BUTTON_LEFT:
            is_clicking = True
            if pygame.Rect(menu.x_pos, 0, *(menu.size * CELL_SIZE)).collidepoint(event.pos):
                new_element = menu.get_new_element(event.pos)
                if new_element is not None:
                    grid_map.current_element = new_element
            elif pygame.Rect(0, 0, *(GRID_SIZE * CELL_SIZE)).collidepoint(event.pos):
                pos = Vector2(event.pos[0], event.pos[1]) / CELL_SIZE
                grid_map.map[int(pos.y)][int(pos.x)] = grid_map.current_element
        elif event.type == pygame.MOUSEBUTTONDOWN and event.button == pygame.BUTTON_RIGHT and\
                pygame.Rect(0, 0, *(GRID_SIZE * CELL_SIZE)).collidepoint(event.pos):
            pos = Vector2(event.pos[0], event.pos[1]) / CELL_SIZE
            grid_map.current_element = grid_map.map[int(pos.y)][int(pos.x)]

        elif event.type == pygame.MOUSEBUTTONUP and event.button == pygame.BUTTON_LEFT:
            is_clicking = False
        elif event.type == pygame.MOUSEMOTION and is_clicking and pygame.Rect(0, 0, *(GRID_SIZE * CELL_SIZE)).collidepoint(event.pos):
            pos = Vector2(event.pos[0], event.pos[1]) / CELL_SIZE
            grid_map.map[int(pos.y)][int(pos.x)] = grid_map.current_element

