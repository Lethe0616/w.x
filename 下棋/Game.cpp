#include "Game.h"
#include <graphics.h>

int Game::_gridSize = 50;//���ӵĴ�С
int Game::_gridCount = 8;//���ӵĸ���
int Game::_winWidth = 640;//���ڵĿ�� 
int Game::_winHeight = 480;//���ڵĸ߶�
int Game::_pieceSize =  _gridSize/2 - 2;//���Ӵ�С 
 
//��ʼλ�õ�x���� 
int Game::_xStart = (_winWidth - _gridSize * _gridCount)/2;

//��ʼλ�õ�y���� 
int Game::_yStart = (_winHeight - _gridSize * _gridCount)/2;

CHESS_PIECE Game::_curplayer = CP_BLACK;//��� 

Game::Game()
{
		
}
	
Game::~Game()
{
	
}

//��Ϸ���� 
void Game::Run()
{
	//�������� 
	_cb.Draw(); 
	
	//�������̲��� 
	_layout.Draw(); 
	
	//���ú��ӺͰ��ӵĸ���
	int bCount=0,wCount=0; 
	
	//�������� 
	_curplayer=CP_BLACK;
	
	//��һ������ 
	_layout.GetResult(bCount,wCount);
	Drawtip(bCount,wCount);
	
	POS pos;
	
	for ( ; is_run(); delay_fps(100) )
	{
		//��ȡ���λ��
		while(!GetMousetHit(pos));
		//�����λ�ÿ������ӣ����������ڿ������ӵ�λ��
 		if(!_layout.IsMaybePosEmpty() && _layout.IsInMaybePos(pos))
 		{
 			//����
 			_layout.SetPieces(pos);
 			//���̻���
 			_cb.Draw();
 			//��������
 			_layout.Draw();
            //�ӳ� 
 			delay_fps(100);
 			
 			//�ı䵱ǰ����
 			_curplayer = (CHESS_PIECE)(3 - _curplayer);
 			
			 //�ڰ���������� 
 			bCount=0,wCount=0;
 			
			 //�����кڰ�������
     		_layout.GetResult(bCount,wCount);
		    Drawtip(bCount,wCount);

 			//������ֺ��޴�����
 			if (_layout.IsMaybePosEmpty())
 			{
 				//����
 				_layout.ChangePlayer();
 				
 				//�ı䵱ǰ����
 				_curplayer = (CHESS_PIECE)(3 - _curplayer);
 				
 				//��������
 				_cb.Draw();
 				//���Ʋ���
 				_layout.Draw();
 				
 				//����������ɫ
	            setcolor(EGERGB(240,255,240));
 				//����߶ȣ������������� 
	            setfont(24,0,"����"); 
	            //�������ֱ���ɫΪ͸�� 
	            setbkmode(TRANSPARENT);
		    
 				xyprintf(0, 0, "����");
 				//����������ӵ�λ��Ϊ�գ�������Ϸ������
 				if (_layout.IsMaybePosEmpty())
 				{
 					//������Ϸ
 					GameOver();
 					break;
				}
 			} 
 		}
	}
	
}


void Game::Drawtip(int bcount,int wcount)
{
	int x,y;
	x=Game::_xStart+415;
    y=Game::_yStart;
    //�ڰ�������ʾ 
    if(CP_BLACK==Game::_curplayer)
    {
    	//����������ɫ
	    setcolor(EGERGB(240,255,240));
 		//����߶ȣ������������� 
	    setfont(20,0,"����"); 
        //�������ֱ���ɫΪ͸�� 
	    setbkmode(TRANSPARENT);
	
    xyprintf(x,y,"������");
    setfillcolor(EGERGB(0,0,0));
    fillellipse(x+50,y+70,Game::_pieceSize,Game::_pieceSize);
    }
    
	if(CP_WHITE==Game::_curplayer)
    {
    	//����������ɫ
	    setcolor(EGERGB(240,255,240));
 		//����߶ȣ������������� 
	    setfont(20,0,"����"); 
        //�������ֱ���ɫΪ͸�� 
    	setbkmode(TRANSPARENT);
	
    xyprintf(x,y,"������");
    setfillcolor(EGERGB(255,255,255));
    fillellipse(x+50,y+70,Game::_pieceSize,Game::_pieceSize);
    }
    
    //���Ӹ��� 
    xyprintf(x,y+200,"���壺%d�� ",bcount);
    xyprintf(x,y+260,"���壺%d�� ",wcount);
     
}

//��ȡ����λ��
bool Game::GetMousetHit(POS& pos)
{
	mouse_msg msg = getmouse();
	
	if(msg.is_left() && msg.is_down())
	{
		if(msg.x - _xStart > 0 && msg.y - _yStart > 0)
		{
			pos.row = (msg.y - _yStart)/_gridSize;
			pos.col = (msg.x - _xStart)/_gridSize;
			
			if(pos.row >=0 && pos.row < _gridCount &&
			pos.col >=0 && pos.col < _gridCount)
			{
				return true;
			}
		}
	}
	
	return false;
}
/*
��Ϸ������Ӯ�ж�
*/
void Game::GameOver()
{
	//�������� 
	_cb.Draw(); 
	
	//�������̲��� 
	_layout.Draw(); 
	
	int blackCount = 0, whiteCount = 0;
	_layout.GetResult(blackCount, whiteCount);
	char str[10];
	if (blackCount > whiteCount)
	{
 		strcpy(str, "����Ӯ��");
	}
	else if (blackCount < whiteCount)
	{
 		strcpy(str, "����Ӯ��"); 
	}
	else
	{
 		strcpy(str, "���壡");
	}
	//����������ɫ
	setcolor(EGERGB(240,255,240));
	//����߶ȣ������������� 
	setfont(24,0,"����"); 
	//�������ֱ���ɫΪ͸�� 
	setbkmode(TRANSPARENT);
	xyprintf(5, 5, "����:%d ����:%d, %s", blackCount, whiteCount, str);
	//��ʾ���
}
