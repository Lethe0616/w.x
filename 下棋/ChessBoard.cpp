#include "ChessBoard.h"
#include <graphics.h>
#include "Game.h"
#include "Layout.h"

ChessBoard::ChessBoard()
{
	
}

ChessBoard::~ChessBoard()
{
	
}

//绘制棋盘
void ChessBoard::Draw()
{
	//清空绘图设备
	cleardevice(); 
	
	//设置前景色 
	setcolor(WHITE); 
	
	PIMAGE bkimg;
	bkimg = newimage();
	
	//加载图片 
	getimage(bkimg, "Images/ChessBoard.jpg");
	putimage(0, 0, bkimg);
	
	//删除图片资源 
	delimage(bkimg);
	
	int x1,x2,y1,y2;
	
	//绘制水平线
	for(int i = 0;i<=Game::_gridCount;++i)
	{
		x1 = Game::_xStart;
		x2 = Game::_winWidth - x1;
		
		y1=y2=Game::_yStart + Game::_gridSize * i;
		
		line(x1,y1,x2,y2);
	}
	
	//绘制垂直线
	for(int i = 0;i<=Game::_gridCount;++i)
	{
		y1 = Game::_yStart;
		y2 = Game::_winHeight - y1;
		
		x1=x2=Game::_xStart + Game::_gridSize * i;
		
		line(x1,y1,x2,y2);
	}
}

