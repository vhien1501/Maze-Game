#include <iostream>
#include <Windows.h>

using namespace std;

char Map[20][20]=	{"###################",
					"#                 #",
					"#                 #",
					"#####    ##########",
					"#                 #",
					"#                 #",
					"#                 #",
					"#                 #",
					"###############   #",
					"#   #             #",
					"#        ##########",
					"#   #             #",
					"#   ###############",
					"#                 #",
					"#                 #",
					"# #############   #",
					"#                 #",
					"#   ####      ### #",
					"#   ####          #",
					"###################"};
					
const int SIDE_LEFT = 0;
const int SIDE_RIGHT = 18;

void ClearScreen(){
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void GotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Board(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			cout<<Map[i][j];
		}
		printf("\n");
	}
}

void DrawPlayer(int x, int y){
	Map[y][x] = '@';
}

void ErasePlayer(int x, int y){
	Map[y][x] = ' ';
}

void Arrow(int x, int y){
	Map[y][x]='-';
	int x2=x-1;
	switch(Map[y][x]){
		case '-':{
			Map[y][x] =' ';
			x--;
			Map[y][x2] = '-';
			if(x2 == 1){
				Map[y][x2]=' ';
			}			
		}
	}
}

void Move(int &x, int &y){
	DrawPlayer(x,y);
	switch(Map[y][x]){
		case '@':{
			if(GetAsyncKeyState(VK_UP) != 0 ){
				int y2 =y-1;
				switch(Map[y2][x]){
					case ' ':{
						ErasePlayer(x,y);
						y--;
						DrawPlayer(x,y2);
					}
				}
			}
	
			if(GetAsyncKeyState(VK_DOWN) != 0){
				int y2 = y+1;
				switch(Map[y2][x]){
					case ' ':{
						ErasePlayer(x,y);
						y++;
						DrawPlayer(x,y2);
					}
				}
			}
	
			if(GetAsyncKeyState(VK_LEFT) != 0 ){
				int x2=x-1;
				switch(Map[y][x2]){
					case ' ':{
						ErasePlayer(x,y);
						x--;
						DrawPlayer(x2,y);
					}
				}
			}
	
			if(GetAsyncKeyState(VK_RIGHT) != 0 ){
				int x2=x+1;
				switch(Map[y][x2]){
					case ' ':{
						ErasePlayer(x,y);
						x++;
						DrawPlayer(x2,y);
					}
				}
			}
		}
	}
	
}



int main(){
	int x=2;
	int y=2;
	int x1=17;
	
	while(true){
		
		ClearScreen();
		
		Board();
		
		Move(x,y);
		
		Arrow(x1,5);
		Arrow(x1,7);
		Arrow(x1,14);
		Arrow(x1,16);
		
		x1--;
		if(x1==1){
			x1=17;
		}
	}
	
}

