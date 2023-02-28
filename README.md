# Sokoban

# Compilation

Via Makefile

```bash
make
``` 
make sure to have the ncurse lib !

# Description

The program is a copy of Sokoban in terminal mode, using the ncurses library.
The game must be reset by pressing the space bar.
The game was able played with the arrow keys (LEFT, RIGHT, UP and DOWN)

# Usage
## Lauch the game
```bash
./sokoban map
```
## Valid map
```bash
> cat map
############
#        O #
# P     ####
#          #
#######    #
#  O ##    #
#    ##    #
#          #
#       XX #
#       #  #
############
```
## Help Command
```bash
./sokoban -h
USAGE
    ./my_sokoban map
DESCRIPTION
    map file representing the warehouse map, containing ‘#’ for walls,
    ‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.
```
