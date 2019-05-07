#include "Game.h"
#include <graphics.h>

int Game::_gridSize = 50;//格子的大小
int Game::_gridCount = 8;//格子的个数
int Game::_winWidth = 640;//窗口的宽度 
int Game::_winHeight = 480;//窗口的高度
int Game::_pieceSize =  _gridSize/2 - 2;//棋子大小 
 
//开始位置的x坐标 
int Game::_xStart = (_winWidth - _gridSize * _gridCount)/2;

//开始位置的y坐标 
int Game::_yStart = (_winHeight - _gridSize * _gridCount)/2;

CHESS_PIECE Game::_curplayer = CP_BLACK;//玩家 

Game::Game()
{
		
}
	
Game::~Game()
{
	
}

//游戏运行 
void Game::Run()
{
	//绘制棋盘 
	_cb.Draw(); 
	
	//绘制棋盘布局 
	_layout.Draw(); 
	
	//设置黑子和白子的个数
	int bCount=0,wCount=0; 
	
	//黑子先行 
	_curplayer=CP_BLACK;
	
	//第一屏数字 
	_layout.GetResult(bCount,wCount);
	Drawtip(bCount,wCount);
	
	POS pos;
	
	for ( ; is_run(); delay_fps(100) )
	{
		//获取鼠标位置
		while(!GetMousetHit(pos));
		//如果有位置可以落子，并且落子在可以落子的位置
 		if(!_layout.IsMaybePosEmpty() && _layout.IsInMaybePos(pos))
 		{
 			//落子
 			_layout.SetPieces(pos);
 			//棋盘绘制
 			_cb.Draw();
 			//绘制落子
 			_layout.Draw();
            //延迟 
 			delay_fps(100);
 			
 			//改变当前棋手
 			_curplayer = (CHESS_PIECE)(3 - _curplayer);
 			
			 //黑白棋个数重置 
 			bCount=0,wCount=0;
 			
			 //容器中黑白棋数量
     		_layout.GetResult(bCount,wCount);
		    Drawtip(bCount,wCount);

 			//如果换手后，无处落子
 			if (_layout.IsMaybePosEmpty())
 			{
 				//换手
 				_layout.ChangePlayer();
 				
 				//改变当前棋手
 				_curplayer = (CHESS_PIECE)(3 - _curplayer);
 				
 				//绘制棋盘
 				_cb.Draw();
 				//绘制布局
 				_layout.Draw();
 				
 				//设置文字颜色
	            setcolor(EGERGB(240,255,240));
 				//字体高度，字体宽带，字形 
	            setfont(24,0,"楷体"); 
	            //设置文字背景色为透明 
	            setbkmode(TRANSPARENT);
		    
 				xyprintf(0, 0, "换手");
 				//如果可以落子的位置为空，结束游戏并返回
 				if (_layout.IsMaybePosEmpty())
 				{
 					//结束游戏
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
    //黑白字行提示 
    if(CP_BLACK==Game::_curplayer)
    {
    	//设置文字颜色
	    setcolor(EGERGB(240,255,240));
 		//字体高度，字体宽带，字形 
	    setfont(20,0,"楷体"); 
        //设置文字背景色为透明 
	    setbkmode(TRANSPARENT);
	
    xyprintf(x,y,"黑子行");
    setfillcolor(EGERGB(0,0,0));
    fillellipse(x+50,y+70,Game::_pieceSize,Game::_pieceSize);
    }
    
	if(CP_WHITE==Game::_curplayer)
    {
    	//设置文字颜色
	    setcolor(EGERGB(240,255,240));
 		//字体高度，字体宽带，字形 
	    setfont(20,0,"楷体"); 
        //设置文字背景色为透明 
    	setbkmode(TRANSPARENT);
	
    xyprintf(x,y,"白子行");
    setfillcolor(EGERGB(255,255,255));
    fillellipse(x+50,y+70,Game::_pieceSize,Game::_pieceSize);
    }
    
    //棋子个数 
    xyprintf(x,y+200,"黑棋：%d个 ",bcount);
    xyprintf(x,y+260,"白棋：%d个 ",wcount);
     
}

//获取鼠标的位置
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
游戏结束输赢判定
*/
void Game::GameOver()
{
	//绘制棋盘 
	_cb.Draw(); 
	
	//绘制棋盘布局 
	_layout.Draw(); 
	
	int blackCount = 0, whiteCount = 0;
	_layout.GetResult(blackCount, whiteCount);
	char str[10];
	if (blackCount > whiteCount)
	{
 		strcpy(str, "黑棋赢！");
	}
	else if (blackCount < whiteCount)
	{
 		strcpy(str, "白棋赢！"); 
	}
	else
	{
 		strcpy(str, "和棋！");
	}
	//设置文字颜色
	setcolor(EGERGB(240,255,240));
	//字体高度，字体宽带，字形 
	setfont(24,0,"楷体"); 
	//设置文字背景色为透明 
	setbkmode(TRANSPARENT);
	xyprintf(5, 5, "黑棋:%d 白旗:%d, %s", blackCount, whiteCount, str);
	//显示结果
}
