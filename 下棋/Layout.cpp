#include "Layout.h"
#include <graphics.h>
#include "Game.h"
#include <algorithm>

Layout::Layout()
{
	//�����������ڴ�
	_layout.resize(Game::_gridCount); 
	
	for(int i = 0;i<Game::_gridCount;++i)
	{
		_layout[i].resize(Game::_gridCount); 
	}
	
	//��ʼ�����̸��ӵ����� 
	for(int i = 0;i<Game::_gridCount;++i)
	{
		for(int j = 0;j<Game::_gridCount;++j)
		{
			_layout[i][j] = CP_NOTHING;
		}
	}
	
	//���ö�Ӧ��λ��Ϊ����
	_layout[3][3] = _layout[4][4] = CP_WHITE;
	
	//���ö�Ӧ��λ��Ϊ����
	_layout[3][4] = _layout[4][3] = CP_BLACK;
	
	//�������
	_player = CP_BLACK; 
	
	GetAllMaybePos();
}

Layout::~Layout()
{
	
}


//��������
void Layout::Draw()
{	
	for(int i = 0;i<Game::_gridCount;++i)
	{
		for(int j = 0;j<Game::_gridCount;++j)
		{
			//����Ǻ��� 
			if(_layout[i][j] == CP_BLACK) 
			{
				//�������ɫΪ��ɫ 
				setfillcolor(EGERGB(0,0,0));

			}
			else if(_layout[i][j] == CP_WHITE)
			{//����ǰ��� 
				//�������ɫΪ��ɫ 
				setfillcolor(EGERGB(255,255,255));
			} 
			else
			{
				continue;
			}
			
			//Բ�ĵ�����
			int x = Game::_xStart + j * Game::_gridSize + Game::_gridSize/2; 
			int y = Game::_yStart + i * Game::_gridSize + Game::_gridSize/2; 
			
			//��������
			fillellipse(x,y,Game::_pieceSize,Game::_pieceSize); 
		}
	}
	
	setfillcolor(EGERGB(255, 255, 0));
	for (int i = 0; i<_allMaybePos.size(); ++i)
	{
		//����Բ�ĵ�λ�� 
		int y = Game::_yStart + _allMaybePos[i].row * Game::_gridSize + Game::_gridSize / 2;
		int x = Game::_xStart + _allMaybePos[i].col * Game::_gridSize + Game::_gridSize / 2;

		//�������п������ӵ�λ��
		fillellipse(x, y, 5, 5);
	}

}

//��������
void Layout::SetPieces(POS pos)
{
	//������ң����ö�Ӧλ�õ�������ɫ
	_layout[pos.row][pos.col] = _player; 

	//��ת����
	TurnPieces(pos); 
	
	ChangePlayer();
	
}

/*
�ж϶�Ӧ��λ���Ƿ������� (���ӻ����)
*/
bool Layout::IsHasPieces(POS pos)
{
	return _layout[pos.row][pos.col] == CP_NOTHING ? false : true;
}


/*
�ж�λ���Ƿ�Ϸ�
*/
bool Layout::IsLegalPos(POS pos)
{
	if (pos.row >= 0 && pos.row < Game::_gridCount &&
		pos.col >= 0 && pos.col < Game::_gridCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
�����������ж�������posλ���Ƿ���һ��������λ��
������	��IsMaybePos
*/

bool Layout::IsMaybePos(POS pos)
{
	bool bret = false;
	POS nextPos;

	for (int row = -1; row <= 1; ++row)
	{
		for (int col = -1; col <= 1; ++col)
		{
			//�������Լ���λ�� 
			if (row == 0 && col == 0)
			{
				continue;
			}

			//������һ���жϵ�λ�� ��8�������е�һ���� 
			nextPos.row = pos.row + row;
			nextPos.col = pos.col + col;

			//���λ�úϷ������Ҳ����жԷ������� 
			if (IsLegalPos(nextPos) && _layout[nextPos.row][nextPos.col] == (CHESS_PIECE)(3 - _player))
			{
				for (nextPos.row += row, nextPos.col += col;
					IsLegalPos(nextPos);
					nextPos.row += row, nextPos.col += col)
				{
					//����ǶԷ������ӣ������ 
					if (_layout[nextPos.row][nextPos.col] ==
						(CHESS_PIECE)(3 - _player))
					{
						continue;
					}
					else if (_layout[nextPos.row][nextPos.col] == _player)
					{//����Ǽ����������򷵻� 
					
					
						return true;
					}
					else
					{//��������������ѭ�� 
						break;
					}
				}
			}

		}
	}
	return false;
}



/*
��ȡ���п������ӵ�λ��
*/
void Layout::GetAllMaybePos()
{
	//������� 
	_allMaybePos.clear();

	POS pos;

	for (pos.row = 0; pos.row < Game::_gridCount; ++pos.row)
	{
		for (pos.col = 0; pos.col < Game::_gridCount; ++pos.col)
		{
			if (!IsHasPieces(pos) && IsMaybePos(pos))
			{
				//�������� 
				_allMaybePos.push_back(pos);
			}
		}
	}

}

/*
����л�
*/
void Layout::ChangePlayer() 

{
		//����л�
		_player = (CHESS_PIECE)(3 - _player);
		//��ȡ���п������ӵ�λ��
		GetAllMaybePos();
}

/*
�жϿ������ӵ�λ���Ƿ�Ϊ��
*/
bool Layout::IsMaybePosEmpty()
{
	return _allMaybePos.empty();
}

/*
�ж������Ƿ��ڿ������ӵķ�Χ��
*/
bool Layout::IsInMaybePos(POS pos)
{
	//����������
	vector<POS>::iterator itr;
	//����
	itr = find(_allMaybePos.begin(), _allMaybePos.end(), pos);
	//����ҵ�
	if (itr != _allMaybePos.end())
	{
		return true;
	}
	else
	{
 		return false;
	}
}


/*
�������ӷ�ת����
*/
void Layout::TurnPieces(POS pos)
{
		POS nextPos;
		for (int row = -1; row <= 1; ++row)
		{
	 	for (int col = -1; col <= 1; ++col)
 		{
 			//�����Լ���λ��
 			if (row == 0 && col == 0)
 			{
 				continue;
 			}
 				//������һ���жϵ�λ�� ��8�������е�һ����
 				nextPos.row = pos.row + row;
 				nextPos.col = pos.col + col;
 				//�������λ�úϷ������Ҳ����д�λ���ǶԷ�������
 				if (IsLegalPos(nextPos) &&
 					_layout[nextPos.row][nextPos.col] == (CHESS_PIECE)(3 - _player))
 				{
 					//������������������
 					for (nextPos.row += row, nextPos.col += col;
 					IsLegalPos(nextPos);
 					nextPos.row += row, nextPos.col += col)
 					{
 						//����ǶԷ������ӣ������
 						if (_layout[nextPos.row][nextPos.col] ==
 							(CHESS_PIECE)(3 - _player))
 						{
 							continue;
 						}
 						else if (_layout[nextPos.row][nextPos.col] == _player)
 						{//����Ǽ��������������ӷ�תΪ��������
 							while (!(nextPos == pos)) 
  						{
 							_layout[nextPos.row][nextPos.col] = _player;
				 			nextPos.row -= row;
 							nextPos.col -= col;
 						}
 						    break;
 						}
 						else
 						{//��������������ѭ��
 							break;
 						}
 					}
 				}
 		}
	}
} 
/*
��ȡ�ڷ��Ͱ׷����ӵ�����
*/
void Layout::GetResult(int& blackCount, int& whiteCount)
{
	for (int i = 0; i<Game::_gridCount; ++i)
	{
 		for (int j = 0; j<Game::_gridCount; ++j)
 		{
 			if (_layout[i][j] == CP_BLACK)
 			{
 				blackCount += 1;
 			}
 			else if (_layout[i][j] == CP_WHITE) 
 			{
 				whiteCount += 1;
 			}
 		}
	}
}

