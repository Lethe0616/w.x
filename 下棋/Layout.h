#ifndef LAYOUT_H
#define LAYOUT_H

#include <vector>
using namespace std;

//����ö�٣���ʾ���̸����е�����
typedef enum{CP_NOTHING,CP_BLACK,CP_WHITE}CHESS_PIECE; 

//�������λ�õĽṹ��
struct POS
{
	int row;//��
	int col;//��
	
	//����������
	bool operator ==(const POS& pos)
	{
		return row == pos.row && col == pos.col;
	} 
	
};

/*
������
*/
class Layout
{
	public:
		Layout();
		~Layout();
		
		void Draw();//��������
		void SetPieces(POS pos);//��������
		
		bool IsHasPieces(POS pos); //�ж϶�Ӧ��λ���Ƿ������� (���ӻ����)
		
		void ChangePlayer();//����л�
		bool IsInMaybePos(POS pos); //�ж������Ƿ��ڿ������ӵķ�Χ��
		bool IsMaybePosEmpty(); //�жϿ������ӵ�λ���Ƿ�Ϊ��
		
		void GetResult(int& blackCount, int& whiteCount);//��ȡ�ڷ��Ͱ׷����ӵ�����
		
	protected:
		vector<vector<CHESS_PIECE> > _layout;//������̵ĸ���
		vector<POS> _allMaybePos; //��¼���п������ӵ�λ��
		CHESS_PIECE _player;//��� 
		
		void GetAllMaybePos();//��ȡ���п������ӵ�λ��
    	bool IsMaybePos(POS pos); //�ж��Ƿ��������
    	bool IsLegalPos(POS pos); //�ж�λ���Ƿ�Ϸ�
    	void TurnPieces(POS pos);

			
};

#endif
