# Conway's Game of Life 

*A C++ command-line game that resembles The Game of Life by John Conway.* \
<img src="https://github.com/calvinjujuis/Conway-Game-of-Life/blob/main/Cell%20Game.png" width="100" height="200">

## Rules from The Game of Life:

> 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
> 2. Any live cell with two or three live neighbours lives on to the next generation.
> 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
> 3. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## Commands:

Command  | Effect
------------- | -------------
p  | print board
o x y | make (x, y) alive
l/a/t/f x y | apply rule 1/2/3/4 to (x, y)
d l/a/t/f | apply rule 1/2/3/4 to all cells
u  | update board
q  | quit


