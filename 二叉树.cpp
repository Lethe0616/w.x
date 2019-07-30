typedef char BTDataType; 

typedef struct BTNode 
{ 
struct BTNode* _pLeft; 
struct BTNode* _pRight; 
int value; 
}BTNode; 


// 1. ���������� 
BTNode* CreateBinTree(BTDataType* array, int size); 
{
	BTNode *node=(BTNode*)malloc(sizeof(BTNode));
	node->value=size;
	node->_pLeft=node->_pRight=null;
	
	return node;
}

// ���������� 
BTNode* CopyBinTree(BTNode* pRoot)
{
    BTNode* newNode=NULL;
    BTNode* newLp=NULL;
    BTNode* newRp=NULL;
    if(pRoot==NULL)
    {
        return NULL;
    }
    if(pRoot->_pLeft!=NULL)
    {
        newLp=CopyTree(pRoot->_pLeft);
    }
    else
    {
        newLp=NULL;
    }
    if(pRoot->rchild !=NULL)
    {
        newRp=CopyTree(pRoot->_pRight );
    }
    else
    {
        newRp=NULL;
    }
    newNode=(BiTNode*)malloc(sizeof(BiTNode));
    if(newNode==NULL)
    {
        return NULL;
    }
    newNode->_pLeft=newLp;
    newNode->_pRight=newRp;
    newNode->data=pRoot->data;
    return newNode;
}

// ���ٶ����� 
void DestroyBinTree(BTNode** pRoot); 
{
    if(pRoot==NULL)
    {
        return ;
    }
    if(pRoot->_pLeft!=NULL)
    {
        DestroyBinTree(pRoot->pLeft);
        pRoot->_pLeft=NULL;
    }
    if(pRoot->_pRight!=NULL)
    {
        DestroyBinTree(pRoot->_pRight);
        pRoot->_pRight=NULL;
    }
    if(pRoot!=NULL)
    {
        free(pRoot);
        pRoot=NULL;
    }
}
// �����������ֱ�����ʽ 
void PreOrder(BTNode* pRoot); 
{
	if(root==null)
	{
		return;
	}
	printf("%d ",pRoot->value);
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);	
}

void InOrder(BTNode* pRoot); 
{
	if(root==null)
	{
		return;
	}
	InOrder(pRoot->_pLeft);
	printf("%d ",pRoot->value);
	InOrder(pRoot->_pRight);	
}

void PostOrder(BTNode* pRoot); 

	if(root==null)
	{
		return;
	}
	PostOrder(pRoot->_pLeft);
	PostOrder(pRoot->_pRight);
	printf("%d ",pRoot->value);	
}

void LevelOrder(BTNode* pRoot); 
{
	if(root==null)
	{
		return;
	}
	std::queue<Node*> q;
	q.push(pRoot);
	
	while(!q.empty())
  {
	Node * front=q.front();q.pop();
	printf("%c ",front->value);
	if(front->left!=null){
		q.push(front->left);
	}
	if(front->right!=null){
		q.push(front->right);
	}
  }
}

// ��ȡ�������нڵ�ĸ��� 
int GetNodeCount(BTNode* pRoot)
{
	if(pRoot==null)
	{
		return 0;
	}
	int left=GetNodeCount(pRoot->_pLeft);
	int right=GetNodeCount(pRoot->_pRight);
	return left+right+1;
}

// ��������ĸ߶� 
int max(int a,int b)
{
	return a>=b?a:b;
}

int Height(BTNode* pRoot) 
{
	if(pRoot==null)
	{
		return 0;
	}
	int left=GetNodeCount(pRoot->_pLeft);
	int right=GetNodeCount(pRoot->_pRight);
	
	return max(left,right)+1;
}

// ���������Ƿ�ƽ��O(N^2) 
int IsBalanceTree(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 1;
	}
	int isBalance = IsBalance(pRoot->_pleft);
	if (isBalance == 0)
	{
		return 0;
	}
	int leftHight = Height(pRoot->_pleft);
	int rightHight = Height(pRoot->_pright);
	int diff = leftHight - rightHight;
	if (diff < -1 && diff>1)
	{
		return 0;
	}
	else {
		return 1;
	}
}

// ���������Ƿ�ƽ��O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height); 
{
	if (pRoot == NULL)
	{
		*height = 0;
		return 1;
	}
	int leftHeight;
	int rightHeight;
	int leftBalance = IsBalance(pRoot->_pleft, &leftHeight);
	int rightBalance = IsBalance(pRoot->_pright, &leftHeight);
	*height = MAX(leftHeight, rightHeight) + 1;
	if (leftBalance == 0 || rightBalance == 0)
	{
		return 0;
	}
	int diff = leftHeight - rightHeight;
	if (diff < -1 || diff>1)
	{
		return 0;
	}
	else {
		return 1;
	}
}

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(BTNode* pRoot)
{
	if(pRoot==null)
	{
		return 0;
	}
	else
	if(pRoot->_pLeft==null&&pRoot->_pRight==null){
		return 1;
	}
	else
	{
		return GetNodeCount(right)+GetNodeCount(left);
	}
}

// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	assert(K>=1);
	if(pRoot==null)
	{
		return 0;
	}
	else
	if(K==1)
	{
	    return 1;
	}
	else
	{
		return GetKLevelNodeCount(pRoot->_pLeft,K-1)+GetKLevelNodeCount(pRoot->_pRight,K-1);
	}
}

// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode,char elem)
{
    if(elem ==pRoot->date)
    {
        if(pNode==NULL)
        {
            cout<<" ";
        }
        else
        {
            cout<<pNode->date;
        }
    }
    if(pRoot->_pLeft!=NULL)
    {
        GetNodeParent(pRoot->_pleft,elem,pRoot);
    }
    if(pRoot->_pright!=NULL)
    {
        GetNodeParent(pRoot->_pright,elem,pRoot);
       
    }
}

// ��������ľ��� 
void Mirror(BTNode* pRoot,BTNode* qRoot)
{
	if(pRoot==null&&qRoot==null)
	{
		return true;
	}
	if(pRoot==null||qRoot==null)
	{
		return false;
	}
	return pRoot->value==qRoot->value&&Mirror(pRoot->_pLeft,qRoot->_pLeft)&&Mirror(pRoot->_pRight,qRoot->_pRight);
}
