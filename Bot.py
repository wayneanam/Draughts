from random import randint

#Maximum size of the board
SIZE = 8


#The keys 1 and 2 stand for players 1 and 2 respectively
#Player one can only move down to the left and down to the right
#Player two can only move up to the left and up to the right
DIRECTION = { 
	1: [(1, -1), (1, 1)],
	2: [(-1,-1), (-1,1)]
}


#Reads the current board states and returns the board, player and opponent
def readBoard():
	board = []

	for i in range(SIZE):
		row = [int(x) for x in input().split()]
		board.append(row)

	player = int(input())
	opponent = 1

	if player == 1:
		opponent = 2
	
	return board, player, opponent 


#This function determines the starting position given a certain player
def getStartPosition(board, player):
	return [(y, x) for x in range(SIZE) for y in range(SIZE) if board[y][x] == player]


#Adds two tuples and returns a tuple
def add(a, b):
	return (a[0] + b[0], a[1] + b[1])


#Checks to see whether a certain position is out of range
def checkBound(position):
	if position[0] < 0 or position[0] >= SIZE:
		return False
	elif position[1] < 0 or position[1] >= SIZE:
		return False

	return True


def analyzeFinal(board, player, position):
	score = 0
	opponent = 1

	if player == 1:
		opponent = 2

	#Favors jumping into empty areas or areas with my own pieces
	for y in DIRECTION[player]:	
		temp = add(y, position)

		if checkBound(temp):
			if board[temp[0]][temp[1]] == player:
				score += 10
			
			elif board[temp[0]][temp[1]] == 0:
				score += 30

			else:
				score -= 10

		else:
			if position[0] == 0 or position[0] == 7:
				score += 50


	return score

def checkNext(board, location, player):
	arr = []

	#Checks the left side
	left = add(location, DIRECTION[player][0])
	
	if checkBound(left) == False:
		pass

	elif board[left[0]][left[1]] == 0:
		pass

	elif board[left[0]][left[1]] != player:
		newLeft = add(left, DIRECTION[player][0])

		if checkBound(newLeft) and board[newLeft[0]][newLeft[1]] == 0:
			arr.append(newLeft)
		

	#Checks the right side
	right = add(location, DIRECTION[player][1])

	if checkBound(right) == False:
		pass

	elif board[right[0]][right[1]] == 0:
		pass

	elif board[right[0]][right[1]] != player:

		newRight = add(right, DIRECTION[player][1])

		if checkBound(newRight) and board[newRight[0]][newRight[1]] == 0:
			arr.append(newRight)


	return arr


#Analyzes a starting location and finds a possible move to make 
def findLocation(board, startLocation, direction, player):
	Move = {
		"start": startLocation,
		"piecesJumped": 0,
		"score": 0,
		"locations": []
	}

	loc = add(startLocation, direction)

	if checkBound(loc) == False:
		return None
	
	elif board[loc[0]][loc[1]] == 0:
		Move["locations"].append(loc)

	elif board[loc[0]][loc[1]] != player:
		locNew = add(loc, direction)

		if checkBound(locNew) and board[locNew[0]][locNew[1]] == 0:
			Move["locations"].append(locNew)
			Move["piecesJumped"] += 1
			possible = checkNext(board, locNew, player)

			while len(possible) != 0:
				nextMove = possible[0]
				Move["locations"].append(nextMove)
				Move["piecesJumped"] += 1
				possible = checkNext(board, nextMove, player)
				
		else:
			return None

	else: 
		return None


	if Move["locations"][-1][1] == 0 or Move["locations"][-1][1] == 7:
		Move["score"] += 100

	Move["score"] += analyzeFinal(board, player, Move["locations"][-1])
	Move["score"] += Move["piecesJumped"] * 100

	return Move



def getMoves(board, player, startPosition):
	allMoves = []

	for x in startPosition:
		for y in DIRECTION[player]:
			tempMove = findLocation(board, x, y, player)

			if tempMove is not None:
				allMoves.append(tempMove)

	return allMoves



def printMove(Move):
	print(str(Move["start"][0]) + " " + str(Move["start"][1]))

	print(len(Move["locations"]))

	for x in Move["locations"]:
		print(str(x[0]) + " " + str(x[1]))



#Displays the board as an 8 * 8 grid
def displayBoard(board):
	for row in board:
		print(" ".join([str(x) for x in row ]))

#Main Function
if __name__ == "__main__":
	board, player, opponent = readBoard()

	startPosition = getStartPosition(board, player)
	allMoves = getMoves(board, player, startPosition)
	highestMove = max(allMoves, key = lambda y: (y["score"]))

	printMove(highestMove)