#include <iostream>
#include <graphics.h>
#include "Game.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
	initgraph(Game::_winWidth,Game::_winHeight);
	
	//…Ë÷√±≥æ∞…´ 
	setbkcolor(EGERGB(0x0,0x40,0x0));
	
	Game game;
	game.Run();
	
	
	getch();
	closegraph();
	
	return 0;
}
