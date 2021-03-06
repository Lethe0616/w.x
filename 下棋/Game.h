#ifndef  GAME_H
#define  GAME_H

#include "ChessBoard.h"
#include "Layout.h"

/*
游戏类 
*/
class Game
{
	public:
		Game();
		~Game();
		
		void Run();//游戏运行 
	protected:
		ChessBoard  _cb;//棋盘对象 
        Layout    _layout;//棋盘布局对象 
	public:
		static int _gridSize;//格子的大小
		static int  _gridCount;//格子的个数
		static int _winWidth;//窗口的宽度 
		static int _winHeight;//窗口的高度
		static int _pieceSize;//棋子大小 
		static int _xStart;//开始位置的x坐标 
		static int _yStart;//开始位置的y坐标 
		static CHESS_PIECE _curplayer;//玩家 
	protected:
		bool GetMousetHit(POS& pos);//获取鼠标位置 
		void GameOver();//游戏结束输赢判定
		void Drawtip(int bcount,int wcount);//提示绘制
		
};

#endif
