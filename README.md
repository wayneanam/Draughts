# Draughts
Battle Of Bots #6 - Hackerearth

Draughts is a two player board game which is played on an 8X8 grid of cells and is played on opposite sides of the game-board. Each player has an allocated color, Red ( First Player ) or White ( Second Player ) being conventional. Players take turns involving diagonal moves of uniform game pieces in the forward direction only and mandatory captures by jumping over opponent pieces.

**Rules:**

- Player can only move diagonally to the adjacent cell and in forward direction, if the diagonally adjacent cell is vacant.
  A player may not move an opponent's piece.
- If the diagonally adjacent cell contains an opponent's piece, and the cell immediately beyond it is vacant, the opponent's piece may be   captured (and removed from the game) by jumping over it in the forward direction only.
- If a player made a jump, then its mandatory to keep on jumping as long as the jump is possible.
- Player cannot move to the diagonally adjacent cell once the player made a jump.
- The game will end when any of the players don't have any move left. At the end of the game the player with majority of pieces will win.

This is a visual representation of the board.

![alt tag](https://github.com/wayneanam/Draughts/blob/master/actualBoard.PNG)

**Running the Bot**

To run the bot, run bot.py and input an 8*8 grid filled with 0's, 1's, and two's. followed by a number either 1 or 2 to indicate which players turn it is. For examples on how a standard input looks like open files firstMove.txt, tripleJump.txt or currentObstacle.txt. Input can be piped in or entered manually.


**Results**

My Bot placed 45th in the competition.
