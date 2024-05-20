// 
Requirements:
1.Timed like chess clock
2. Are there any undo moves allowed
3. Can the game be spectated
4. statistics for the users (Will there be any rating change)
5. Is there any tournament 
6. Are there any AI frameworks used in the system

Class Game board: int[n][n] 0,1,2  WINNER -> "first" "SECOND" "DRAW" "undecided"
INITIALIZING THE BOARD
GET WINNER GET BOARD STATUS
GET CURRENT PLAYER
MAKEMOVE(MOVE M) PLAYER, ROW, COLUMN

CLASS USER: USER ID, STATISTICS (WINS, LOSSES, HIGHEST OPPONENT ....)
CLASS GAME : GAME ID , USER ID 1 , ISER ID 2 , LIST<MOVES>  
// Online C++ compiler to run C++ program online
  
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
class User{
    private:
    int userId;
    public:
    User(int n){
        userId=n;
    }
    int getuserId(){
        return userId;
    }
};

class Board{
    vector<vector<int> > board;
    vector<int> row;
    vector<int> col;
    int diagSum;
    int revdiagSum;
    User* winner;
    int n;
    public:
    Board(int size){
        board= vector<vector<int> >(size,vector<int>(size, 0));
        row = vector<int> (size,0);
        col = vector<int> (size,0);
        n = size;
    }
    void showBoard(){
        cout<<"size of board "<<n<<endl;
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        cout<< "print row sum vector"<<endl;
        for (int i = 0; i < n; ++i) {
            cout<<row[i]<< " ";
        }
        cout<<endl<<"print col sum vector"<<endl;
        for (int i = 0; i < n; ++i) {
            cout<<col[i]<< " ";
        }
    }
    auto move(User* player, int r, int c){
        if(board[r][c] !=0){
            cout<<"Square is already occupied"<<endl;
        }
        else if(player->getuserId()!=0 && player->getuserId()!=1){
            cout<<"Invalid Player!"<<endl;
        }
        else{
            int point = 1;
            if(player->getuserId()==0){
                point = -1;
            }
            board[r][c] = point;
            row[r]+=point;
            col[c]+=point;
            if(r==c){
                diagSum += point;
            }
            if(r == n-1-c){
                revdiagSum += point;
            }
            if(row[r] == abs(n) || col[c] == abs(n) || diagSum == abs(n) || revdiagSum == abs(n)){
                winner=player;
                return "WINNER";
            }
            return "UNDECIDED";
        }
         return "UNDECIDED";
    }
};

class Game {
    private: 
    int gameId;
    User* player1;
    User* player2;
    public:
    Game(int n, User *p1,User *p2){
        gameId=n;
        player1 = p1;
        player2 = p2;
    }
     void getGameID(){
        cout<< "game id "<<gameId<<endl;
    }
    void ListofMoves(Board* board){
       cout<<board->move(player1,0,0)<<endl;
       cout<<board->move(player1,1,0)<<endl;
       cout<<board->move(player2,2,0)<<endl;
       cout<<board->move(player2,2,1)<<endl;
       cout<<board->move(player2,2,2)<<endl;
    }
};


int main() {
    User* p1 = new User(1);
    User* p2 = new User(0);
    Game *game = new Game(100,p1,p2);
    Board* board = new Board(3);
    p1->getuserId();
    p2->getuserId();
    game->ListofMoves(board);
    board->showBoard();
    return 0;
}
