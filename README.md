Cub3D is a project that implements a raycasting algorithm to create a 3D representation of a 2D grid or map. The project is written in C and uses the minilibx library for rendering the resulting image on the screen.



// add a video here


The project includes a Makefile that can be used to build and install the project and its dependencies. To build  the project

The project takes a .cub file as input, which contains a grid of characters representing the 2D map or scene that the raycasting algorithm will be used to render. The .cub file should use the following convention


    '1' represents a wall or solid object in the scene
    '0' represents a free space or open area in the scene
    'W', 'S', 'E', or 'N' represents the direction of the player's field of view

Example : [example.cub](./map/younes.cub)
