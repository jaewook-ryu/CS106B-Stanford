
#include "Maze.h"


bool escapeMaze(Maze& maze, int row, int col){
    // base case
    if(!maze.inBounds(row, col)){
        return true;
    } else if(maze.isWall(row, col)){
        return false;
    } else if(!maze.isOpen(row, col)){
        // choose step
        maze.mark(row, col);

        // exploring steps
        bool result = escapeMaze(maze, row-1, col) || escapeMaze(maze, row+1, col) ||
                escapeMaze(maze, row, col-1) || escapeMaze(maze, row, col+1);

        // un-choose if it is not a good result
        if(!result){
            maze.taint(row, col);
        }

        return result;

    } else{
        return false;
    }



}
