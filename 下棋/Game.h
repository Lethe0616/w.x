#ifndef  GAME_H
#define  GAME_H

#include "ChessBoard.h"
#include "Layout.h"

/*
��Ϸ�� 
*/
class Game
{
	public:
		Game();
		~Game();
		
		void Run();//��Ϸ���� 
	protected:
		ChessBoard  _cb;//���̶��� 
        Layout    _layout;//���̲��ֶ��� 
	public:
		static int _gridSize;//���ӵĴ�С
		static int  _gridCount;//���ӵĸ���
		static int _winWidth;//���ڵĿ�� 
		static int _winHeight;//���ڵĸ߶�
		static int _pieceSize;//���Ӵ�С 
		static int _xStart;//��ʼλ�õ�x���� 
		static int _yStart;//��ʼλ�õ�y���� 
		static CHESS_PIECE _curplayer;//��� 
	protected:
		bool GetMousetHit(POS& pos);//��ȡ���λ�� 
		void GameOver();//��Ϸ������Ӯ�ж�
		void Drawtip(int bcount,int wcount);//��ʾ����
		
};

#endif
