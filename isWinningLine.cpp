/******************

Alfie Thomasson 
Language: C++
isWinningLine Function created for assessment

Connect Four board is assumed to be a 2D Vector with integers representing the game state.
 
 0 = Empty Space
 1 = Player 1
 2 = Player 2

 This function takes in the current board as well as the co-ordinates of the last played piece 
 and then checks whether the piece being played would cause the player to win.  

 A win is defined as the player having four or more of their pieces connected to each other horizontally, vertically, or diagonally.

******************/

bool isWinningLine(std::vector<std::vector<int>> board, int x, int y)
{ 

    //Assigning the player who played the last piece so we can check if they have won
    int player = board[x][y];

    //Breaking down our checks into four different functions
    //If any return true then the player has won
    if (checkHorizontal(board, x, y, player)
        || checkVertical(board, x, y, player)
        || checkDiagonalNESW(board, x, y, player)
        || checkDiagonalNWSE(board, x, y, player))
    {
        return true;
    }
    else
    {
        //Player has not placed a winning piece
        return false;
    }
}

//Function to check if four of the players pieces connect horizontally
bool checkHorizontal(std::vector<std::vector<int>> board, int x, int y, int player)
{
    //Count integer to store how many spaces we are from our starting piece
    int pieceCount = 1;
    //Score integer for how many pieces we have currently connected
    int curScore = 1;
    // Horizontal Check
   // First we check how many of our pieces are to the right of us, ensuring we stay within the game board
    while ((x + pieceCount > 0) && (x + pieceCount) < board.size())
    {
        //Check if there is a piece of our type in this space
        if (board[x + pieceCount][y] == player)
        {
            //And if so we iterate the count so we can check the next space along
            pieceCount++;
            //And we increase the score so we can tell later if we have found 4 in a row.
            curScore++;
        }
        else
        {
            //If next space found does not contain a relevant piece, we break out of the loop
            break;
        }
    }

    //Reset the count
    pieceCount = 1;
    //Now we check how many pieces are to the left of us, ensuring we stay within the game board
    while ((x - pieceCount >= 0) && (x - pieceCount) < board.size())
    {
        //Check if there is a piece of our type in this space
        if (board[x - pieceCount][y] == player)
        {
            pieceCount++;
            curScore++;
        }
        else
        {
            break;
        }
    }

    //Check if we have found four connected pieces, and if so return true as the player has won
    if (curScore >= 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Function to check if four of the players pieces connect vertically
bool checkVertical(std::vector<std::vector<int>> board, int x, int y, int player)
{
    //Define our integers 
    int pieceCount = 1;
    int curScore = 1;

    //Checks if the pieces below us are the players pieces
    while ((y + pieceCount > 0) && (y + pieceCount) < board[0].size())
    {
        //If the piece in this space is of the players type
        if (board[x][y + pieceCount] == player)
        {
            pieceCount++;
            curScore++;
        }
        else
        {
            break;
        }
    }

    if (curScore == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Function to check if four of the players pieces connect from North East to South West
bool checkDiagonalNESW(std::vector<std::vector<int>> board, int x, int y, int player)
{
    int pieceCount = 1;
    int curScore = 1;

    //Checks if the pieces North East of the start piece are of the players type
    while ((x + pieceCount < board.size()) && (y - pieceCount) > 0)
    {
        //Check current space to see if it belongs to the player
        if (board[x + pieceCount][y - pieceCount] == player)
        {
            pieceCount++;
            curScore++;
        }
        else
        {
            break;
        }
    }

    pieceCount = 1;
    //Check the pieces South West of the start piece
    while ((x - pieceCount > 0) && (y + pieceCount) < board[0].size())
    {
        if (board[x - pieceCount][y + pieceCount] == player)
        {
            pieceCount++;
            curScore++;
        }
        else
        {
            break;
        }
    }

    if (curScore >= 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Function to check if four of the players pieces connect from North West to South East
bool checkDiagonalNWSE(std::vector<std::vector<int>> board, int x, int y, int player)
{
    int pieceCount = 1;
    int curScore = 1;

    //Checks if the pieces North West of the start piece are of the players type
    while ((x - pieceCount > 0) && (y - pieceCount) > 0)
    {
        if (board[x - pieceCount][y - pieceCount] == player)
        {
            pieceCount++;
            curScore++;
        }
        else
        {
            break;
        }
    }

    pieceCount = 1;
    //Checks if the pieces South East of the start piece are of the players type
    while ((x + pieceCount < board.size()) && ((y + pieceCount) < board[0].size()))
    {
        if (board[x + pieceCount][y + pieceCount] == player)
        {
            pieceCount++;
            curScore++;
        }
        else
        {
            break;
        }
    }

    if (curScore >= 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}