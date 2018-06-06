//Author Anirudh Yadav
//Coursera Assignment Game of HEX (you win or you die)

various classes

1. POINT- It represents a vertex on the board, it is a tuple (row,column).
2. VERTEX- A vertex is denoted by a point and each location in the board is a vertex. Each vertex has an owner(CROSS, ZERO, BLANK) 
3. EDGE- An edge represents adjacency of 2 vertexs on a board. If two vertexs are adjacent the graph will have an edge connecting these two vertexs.
4. GRAPH- It is a set of two lists one for the vertexs of the graph and second one for the edges of the graph. It has various functions performing specific tasks and are further explained in the comments. 

/// other auxillary files

1. game.cpp- It contains functions that help in the playing the game like printing the board and checking for winner. 
2. main.cpp- It combines all the above files and facilitates the game. It also contain the function implementing monte carlo algorithm, the function name is next_best_move().


///Game flow

- Asks for the size of board.
- Display the board and give some instructions. 
- Ask for the input from player one. 
- Display the board.
- Player 2 is the computer player.
- Display the board. 
- As soon as any one wins, display the result and exit.

// to test the code you can either run a.out or compile the files using "g++ point.cpp vertex.cpp edge.cpp graph.cpp game.cpp main.cpp -o a.out".

