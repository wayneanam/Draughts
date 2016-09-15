//Format [(up,down), (left,right)]

#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Global constants and variables
const int SIZE = 8;
int playerID, oppID;

//Indicates the starting position of a given piece
struct LocationXY
{
  int y;
  int x;
};

//Indicates the new location and the number of jumps
struct LocationXYZ
{
  int y;
  int x;
  int z;
};

bool operator <(const LocationXY& lhs, const LocationXY& rhs) 
{
  if(lhs.y < rhs.y)
  {
    return lhs.y;
  }
  else
  {
    return rhs.y;
  }
};


//Functions
void readBoard(int board[][SIZE]);
void possibleMoves(int board[][SIZE], multimap<LocationXY, LocationXYZ>& moves);
void search(int board[][SIZE], multimap<LocationXY, LocationXYZ>& moves, LocationXY point, LocationXYZ pointXYZ);
void chooseMove(multimap<LocationXY, LocationXYZ>& moves);

int main()
{
  int board[SIZE][SIZE];
  multimap<LocationXY, LocationXYZ> moves;
  

  readBoard(board);
  possibleMoves(board, moves);
  chooseMove(moves);
  
  
  
  return 0;
}

void readBoard(int board[][SIZE])
{ 
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      cin>>board[i][j];
    }
  }
  
  cin>>playerID;
  
  if(playerID == 1)
  {
    oppID = 2;
  }
  else
  {
    oppID = 1;
  }
}

void possibleMoves(int board[][SIZE], multimap<LocationXY, LocationXYZ>& moves)
{
  LocationXY point;
  LocationXYZ pointXYZ;
  
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      if(board[i][j] == playerID)
      {
        point.y = i;
        point.x = j;
        search(board, moves, point, pointXYZ);
      }
    }
  } 
}

void search(int board[][SIZE], multimap<LocationXY, LocationXYZ>& moves, LocationXY point, LocationXYZ pointXYZ)
{
  //Location pos;
  //Going down the board
  if(playerID == 1) 
  {
    //Check the left diagonal for a possible move
    if(((point.y + 1) < SIZE) && ((point.x - 1) > -1))
    {
      pointXYZ.y = point.y + 1;
      pointXYZ.x = point.x - 1;
      
      //Check if the space is occupied 
      if(board[pointXYZ.y][pointXYZ.x] == 0)
      {
        pointXYZ.z = 1;  
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));
      }
      else if(board[pointXYZ.y][pointXYZ.x] == oppID)
      {
        return;
        pointXYZ.z = 1;
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));        
        //Check for jumps
      }
    }
    //Check the right diagonal for a possible move
    else if(((point.y + 1) < SIZE) && ((point.x + 1) < SIZE))
    {
      pointXYZ.y = point.y + 1;
      pointXYZ.x = point.x - 1;
      
      //Check if the space is occupied 
      if(board[pointXYZ.y][pointXYZ.x] == 0)
      {
        pointXYZ.z = 1;  
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));        
      }
      else if(board[pointXYZ.y][pointXYZ.x] == oppID)
      {
        return;
        pointXYZ.z = 1;
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));        
        //Check for jumps
      }
    }
  }
  else 
  {
    //Going up the board
    //Check the left diagonal for a possible move
    if(((point.y - 1) > -1) && ((point.x - 1) > -1))
    {
      pointXYZ.y = point.y + 1;
      pointXYZ.x = point.x - 1;
      
      //Check if the space is occupied 
      if(board[pointXYZ.y][pointXYZ.x] == 0)
      {
        pointXYZ.z = 1;  
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));        
      }
      else if(board[pointXYZ.y][pointXYZ.x] == oppID)
      {
        pointXYZ.z = 1;
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));        
        //Check for jumps
      }
    }
    //Check the right diagonal for a possible move
    if(((point.y - 1) > -1) && ((point.x + 1) < SIZE))
    {
      pointXYZ.y = point.y + 1;
      pointXYZ.x = point.x - 1;
      
      //Check if the space is occupied 
      if(board[pointXYZ.y][pointXYZ.x] == 0)
      {
        pointXYZ.z = 1;  
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));        
      }
      else if(board[pointXYZ.y][pointXYZ.x] == oppID)
      {
        pointXYZ.z = 1;
        moves.insert(pair<LocationXY, LocationXYZ>(point, pointXYZ));        
        //Check for jumps
      }
    }  
  }
}

void chooseMove(multimap<LocationXY, LocationXYZ>& moves)
{
  for(auto i = moves.begin(); i != moves.end(); ++i)
  {
    cout<<i->first.y<<" "<<i->first.x<<endl;
    cout<<i->second.z<<endl;
    cout<<i->second.y<<" "<<i->second.x<<endl;
  }
}
