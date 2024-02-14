cout<<"i este "<<i<<endl;
return bestMove;
}
int MaxMove(stateT state, moveT &bestMove)
{
if(GameIsOver(state))
{
return EvaluateStaticPosition(state);
}
vector<moveT> moveList;
GenerateMoveList(state, moveList);
int nMoves = moveList.size();
int v = -1000;
for(int i = 0 ;i<nMoves; i++)
{
moveT move = moveList[i];
MakeMove(state, move);
int curRating = MinMove(state,bestMove);
if (curRating > v)
{
v = curRating;
bestMove = move;
}
RetractMove(state, move);
}
return v;
}
int MinMove(stateT state, moveT &bestMove)
{
if(GameIsOver(state))
{
return EvaluateStaticPosition(state);
}
vector<moveT>moveList;
GenerateMoveList(state, moveList);
int nMoves = moveList.size();
int v = 1000;
for(int i = 0 ; i<nMoves; i++)
{
moveT move = moveList[i];
MakeMove(state , move);
int curRating = MaxMove(state,bestMove);
if(curRating < v)
{
v = curRating;
}
RetractMove(state, move);
}
return v;
}
moveT ChooseComputerMove(stateT state)
{
int rating ;
cout<<"mutarea mea."<<endl;
return MiniMax(state);
}
void GenerateMoveList(stateT state, vector<moveT> & moveList)
{
for(int i = 1; i <=9 ; i++)
{
moveT move = moveT(i);
if(MoveIsLegal(move, state))
{
moveList.push_back(moveT(i));
}
}
}
bool MoveIsLegal(moveT move, stateT state)
{
if(move < 1 || move > 9) return false;
int row = (move - 1) /3;
int col = (move -1) %3;
return state.board[row][col] == ' ';
}
//Returning the move of the player in character form
char PlayerMark(playerT player)
{
if(player == FIRST_PLAYER)
{
return 'X';
}
else
{
return 'O';
}
}
playerT Opponent(playerT player)
{
return (player == Human) ? Computer : Human;
}
//If a human
void MakeMove(stateT &state, moveT move)
{
int row = (move - 1) / 3;
int col = (move - 1) %3;
state.board[row][col] = PlayerMark(state.whoseTurn);
state.whoseTurn = Opponent(state.whoseTurn);
state.turnsTaken++;
}
void RetractMove(stateT & state, moveT move)
{
int row = (move - 1) /3;
int col = (move -1) % 3;
state.board[row][col] = ' ';
state.whoseTurn = Opponent(state.whoseTurn);
state.turnsTaken--;
}
bool GameIsOver(stateT state)
{
return (state.turnsTaken == 9 || CheckForWin(state, state.whoseTurn)||
CheckForWin(state, Opponent(state.whoseTurn)));
}
playerT WhoseTurn(stateT state)
{
return state.whoseTurn;
}
int EvaluateStaticPosition(stateT state)
{
if(CheckForWin(state, state.whoseTurn))
{
return WINNING_POSITION;
}
if(CheckForWin(state, Opponent(state.whoseTurn)))
{
return LOSING_POSITION;
}
return NEUTRAL_POSITION;
}
bool CheckForWin(stateT state, playerT player)
{
if(state.turnsTaken < 5) return false;
return CheckForWin(state.board, PlayerMark(player));
}
//Checking for win
bool CheckForWin(vector< vector<char> > & board, char mark)
{
for(int i = 0 ; i < 3; i++)
{
if(CheckLine(board, mark, i,0,0,1)) return true;
if(CheckLine(board, mark, 0,i,1,0)) return true;
}
if(CheckLine(board, mark, 0,0,1,1)) return true;
return CheckLine(board, mark, 2, 0, -1, 1);
}
//Checking for win
bool CheckLine(vector<vector<char> > & board, char mark , int row , int col,int dRow,
int dCol)
{
for(int i = 0 ; i < 3; i++)
{
if(board[row][col] != mark) return false;
row += dRow;
col += dCol;
}
return true;
}
//Announce the result of the game
void AnnounceResult(stateT state) {
DisplayGame(state);
if (CheckForWin(state, Human)) {
cout << "ai castigat!" << endl;
} else if (CheckForWin(state, Computer)) {
cout << "am castigat!" << endl;
} else {
cout << "Joc finalizat fara castig" << endl;
}
}
//Give instructions to the player
void GiveInstructions()
{
cout<<"bine ati venit la x si 0! obiectul jocului este "<<endl;
cout<<"sa aliniem trei simboluri intr-un rand"<<endl;
cout<<"vertical , orizontal , sau diagonal"<<endl;
cout<<"vei fi "<<PlayerMark(Human)<<" si voi fi
"<<PlayerMark(Computer)<<"."<<endl;
}
int main()
{
GiveInstructions();
stateT state = NewGame();
moveT move;
while(!GameIsOver(state))
{
DisplayGame(state);
switch(WhoseTurn(state))
{
case Human:
move = GetUserMove(state);
break;
case Computer:
move = ChooseComputerMove(state);
DisplayMove(move);
break;
}
MakeMove(state, move);
}
AnnounceResult(state);
return 0;
}
