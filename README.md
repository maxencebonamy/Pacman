# Pacman

## Build & run

### macOS

```bash
brew install cmake sfml@2
cmake -S . -B build
cmake --build build
./build/Pacman
```

The game loads its assets from `res/`, so run it from the project root.

### Windows (MinGW 32-bit)

The bundled SFML in `lib/SFML` is picked up automatically by CMake.
