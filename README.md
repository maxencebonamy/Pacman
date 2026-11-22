# Pacman

A Pacman clone written in C++ with SFML.

Guide Pacman through a maze loaded from a text file, eat every pacgum and avoid the four ghosts. The project also ships a small Python map editor to design new mazes.

## Table of contents

- [Pacman](#pacman)
	- [Table of contents](#table-of-contents)
	- [How it works](#how-it-works)
	- [Tech stack](#tech-stack)
	- [Repository structure](#repository-structure)
	- [Prerequisites](#prerequisites)
	- [Installation](#installation)
	- [Configuration](#configuration)
	- [Running locally](#running-locally)
	- [Useful scripts](#useful-scripts)
	- [License](#license)

## How it works

1. **Start**: the game opens a window and shows a 3-second countdown before the round begins.
2. **Controls**: the arrow keys change Pacman's direction. `Esc` or closing the window quits.
3. **Maze**: the map is read from `res/map/map.txt`. Each cell holds a tile name (wall, pacgum, super pacgum, center cell, void) and tiles are drawn from the images in `res/img/map`.
4. **Ghosts**: Blinky, Inky, Clyde and Pinky start in the center of the maze. Touching a ghost kills Pacman and the death animation plays.
5. **Super pacgums**: eating one scares the ghosts. A scared ghost that touches Pacman dies instead of killing him.
6. **End**: the game shows `Win!` once no pacgum or super pacgum is left on the map, and `Lose!` after Pacman's death animation.

## Tech stack

| Layer | Technologies |
| --- | --- |
| Game | C++, SFML 2 (`system`, `window`, `graphics`) |
| Map editor | Python, pygame |
| Build | CMake 3.10 or later |
| Assets | PNG sprites, `pacman.ttf` font, semicolon-separated map files |

## Repository structure

```
.
├── src/
│   ├── main.cpp         Window creation and main loop
│   ├── game.cpp         Game states, collisions, win and lose conditions
│   ├── config.cpp       Window title, size, fullscreen flag and frame rate
│   ├── entities/        Entity, player, direction and the four ghosts
│   ├── map/             Map loading, update and display
│   ├── display/         Image, animated image and label wrappers
│   ├── utils/           Vector2, Rect and Timer
│   └── map_maker/       Python map editor
├── res/
│   ├── img/             Sprites for Pacman, ghosts, fruits and map tiles
│   ├── map/             Map files
│   └── font/            Font used for labels
├── lib/SFML/            SFML for Windows (MinGW 32-bit)
└── CMakeLists.txt
```

All `.cpp`, `.hpp` and `.tpp` files under `src/` are compiled automatically by CMake, so a new source file does not need to be registered. Classes are split into a `.hpp` and a `.cpp` file of the same name.

## Prerequisites

- [CMake](https://cmake.org/) 3.10 or later
- A C++ compiler
- [SFML](https://www.sfml-dev.org/) 2
  - macOS: the `sfml@2` Homebrew formula
  - Windows: the copy bundled in `lib/SFML`, built for MinGW 32-bit
- Python 3 and [pygame](https://www.pygame.org/), only to use the map editor

## Installation

```bash
git clone git@github.com:maxencebonamy/Pacman.git
cd Pacman
```

On macOS:

```bash
brew install cmake sfml@2
cmake -S . -B build
cmake --build build
```

On Windows with MinGW 32-bit, CMake picks up the bundled SFML in `lib/SFML` automatically.

```bash
cmake -S . -B build
cmake --build build
```

## Configuration

The game has no environment file. Window settings are constants in `src/config.cpp`, and the executable has to be rebuilt after changing them.

| Constant | Description | Value |
| --- | --- | --- |
| `WINDOW_TITLE` | Window title | `Pacman` |
| `WINDOW_SIZE` | Window size in pixels | `1280 x 720` |
| `WINDOW_FULLSCREEN` | Fullscreen mode | `false` |
| `WINDOW_FPS` | Frame rate limit | `120` |

The map loaded at startup is set in the `Game` constructor in `src/game.cpp` (`map`, which is `res/map/map.txt`).

## Running locally

The game loads its assets from `res/` with relative paths, so run it from the project root.

```bash
./build/Pacman
```

To design a map, run the editor from the project root as well:

```bash
python src/map_maker/main.py
```

Left click places the selected tile, right click picks the tile under the cursor, and the tile palette is on the right of the grid. The map is written to `res/map/testt.txt` when the window is closed.

## Useful scripts

| Command | Effect |
| --- | --- |
| `cmake -S . -B build` | Configure the project |
| `cmake --build build` | Build the `Pacman` executable |
| `./build/Pacman` | Start the game |
| `python src/map_maker/main.py` | Start the map editor |

## License

This project is licensed under the [MIT License](LICENSE).
