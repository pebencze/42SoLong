# SoLong

So Long is a small 2D game project designed to enhance your skills in working with textures and basic gameplay elements. This project uses the MiniLibX graphical library to help you understand window management, event handling, and other fundamental graphics programming concepts. Throughout the project you also learn a lot about parsing and the floodfill algorithm.

## Mandatory Features
### Game Mechanics

- The player's goal is to collect all collectibles on the map and reach the exit via the shortest route.
- Movement controls: W, A, S, D (or ZQSD or arrow keys) for up, left, down, and right respectively.
- Movements must be displayed in the shell.
- The game uses a 2D view (top-down or profile).

### Graphic Management

- Display the game in a window.
- Ensure smooth window management (e.g., minimizing, changing focus).
- Pressing ESC or clicking the window's close button must quit the game cleanly.
- Utilize MiniLibX images for graphical elements.

### Map Requirements

- Maps must contain walls, collectibles, and free space, defined by characters:
  0: Empty space
  1: Wall
  C: Collectible
  E: Exit
  P: Player’s starting position
- Maps must have one exit, at least one collectible, and one starting position.
- Maps must be rectangular and surrounded by walls.
- Validate the map for a correct path and configuration.
Example of a valid map:

      1111111111111
      10010000000C1
      1000011111001
      1P0011E000001
      1111111111111
  
## How to Run

1. Clone the repository:

        git clone <repository_url>

2. Compile the project using the provided Makefile:

        make

3. Run the game with a map file:

        ./so_long path/to/map.ber
