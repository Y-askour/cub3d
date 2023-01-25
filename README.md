https://user-images.githubusercontent.com/49567393/214644991-3d1f01c4-5fdb-4e17-8c99-ae0b80233211.mp4

Cub3D is a project that implements a raycasting algorithm to create a 3D representation of a 2D grid or map. The project is written in C and uses the minilibx library for rendering the resulting image on the screen.

https://user-images.githubusercontent.com/49567393/214645061-d21fc407-c546-4306-8d8e-18b47d1198ab.mp4


The project includes a Makefile that can be used to build and install the project and its dependencies. To build  the project

The project takes a .cub file as input, which contains a grid of characters representing the 2D map or scene that the raycasting algorithm will be used to render. The .cub file should use the following convention


    '1' represents a wall or solid object in the scene
    '0' represents a free space or open area in the scene
    'W', 'S', 'E', or 'N' represents the direction of the player's field of view

Example : [example.cub](./map/younes.cub)

```
SO textures/wall_y.xpm
NO textures/wall_h.xpm
WE textures/wall_3.xpm
EA textures/4.xpm

F   198,198,198
C 60,60,60


        1111111111111111111111111
        1000000000110000000000001
        1011000001110011100000111
        100100000000001 100000001
111111111011000001110011100000001
100000000011000000000000100011111
11110111111111011100000010001111111111111111111111
11110111000111011101010010001000000000000000000001
11110111000111011101010010000000001111111111111111
111100000000000000000000000000010010001      1
111100000000000000000000000001010010001      1
111100000001000000100000010101010010001      1
11110000001010000N0101000000000101001001      1
111100000001000000000000011101010010001      1
111100000000000000000000000001010010001      1
111100000000000000000000011101010010001      1
111100000000000000000000001001010010001      1
1111000000000000000000000000010100100011     1
11110000000000011101010010001111111111001    1
11000000110101011100000010001        11001   1
10000000000000001100000010001         10001  1
10000000000000001101010010001         10000111
11000001110101000111101011000111111111110000011
11110111 1110101110111100000000000000000000001
11111111 1111111 11111111111111111111111111111
11111111 1111111 11111111111111111111111111111
```

Once you have provided a .cub file as input, you can run the project to render the 3D representation of the map on the screen. The project also supports user input, allowing you to move the viewpoint around the scene and interact with the environment using the arrow keys to rotate the player's field of view and the W/S/A/D keys to move forward, backward, left, and right, respectively.

## Contributors

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://github.com/YOPll"><img src="https://avatars.githubusercontent.com/u/49567393?v=4" width="100px;" alt=""/><br /><sub><b>Zakaria Yacoubi</b></sub></a><br /><a href="YOPIIIIIIIII" title="Code">💻</a> <a href="#Cub3D Projection" title="Code">🚇</a></td>
    <td align="center"><a href="https://github.com/Y-askour"><img src="https://avatars.githubusercontent.com/u/66399701?v=4" width="100px;" alt=""/><br /><sub><b>Y-askour</b></sub></a><br /><a href="Y-askour" title="Code">💻</a></td>
  </tr>
</table>

<!-- markdownlint-enable -->
<!-- prettier-ignore-end -->
<!-- ALL-CONTRIBUTORS-LIST:END -->
