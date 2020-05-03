#include <iostream>
#include <vector>


// 想得太复杂，不太适合用来解这一题
// 用一维数组来解比较好；数据结构有问题
using namespace std;

struct HeapStruct
{
public:
    int key;
    HeapStruct *left;
    HeapStruct *right;
    HeapStruct *myHead;
    HeapStruct() : key(0),
                   left(NULL),
                   right(NULL),
                   myHead(NULL)
    {
    }
    HeapStruct(int a) : key(a),
                        left(NULL),
                        right(NULL),
                        myHead(NULL)
    {
    }
};

static HeapStruct *Head = NULL;

static HeapStruct *endHead = NULL;

static int HeapDepth = 0;

static vector<vector<int> > bufForPrint;

void RefreshDepth()
{
    HeapDepth = 0;
    bufForPrint.clear();
    if (Head == NULL)
    {
        HeapDepth = 0;
        return;
    }
    HeapStruct *headDep = Head;
    vector<int> tempVector;
    bufForPrint.push_back(tempVector);
    while (headDep->left != NULL)
    {
        vector<int> tempVector;
        bufForPrint.push_back(tempVector);
        headDep = headDep->left;
    }
}

void FindEnd(HeapStruct *pHead)
{
    if (pHead == NULL)
    {
        return;
    }

    if (pHead->left == NULL && pHead->right == NULL)
    {
        endHead = pHead;
        return;
    }
    else
    {
        FindEnd(pHead->left);
        FindEnd(pHead->right);
    }
}

void AdjustHeap()
{
    if (endHead == NULL)
    {
        return;
    }
    while (endHead->myHead != NULL && endHead->key < endHead->myHead->key)
    {
        int temp = endHead->key;
        endHead->key = endHead->myHead->key;
        endHead->myHead->key = temp;
        endHead = endHead->myHead; // move up
    }
}

void AddHeap(int a)
{
    HeapStruct *NewNode = new HeapStruct(a);
    if (Head == NULL)
    {
        Head = NewNode;
        NewNode->myHead = NULL;
        return;
    }

    endHead = NULL;
    FindEnd(Head);
    if(endHead->myHead != NULL && endHead->myHead->left == NULL){
        endHead->myHead->left = NewNode;
        NewNode->myHead = endHead->myHead;
    }else if((endHead->myHead != NULL && endHead->myHead->right == NULL)){
        endHead->myHead->right = NewNode;
        NewNode->myHead = endHead->myHead;

    }else if(endHead->myHead->left->left == NULL){
        endHead->myHead->left->left = NewNode;
        NewNode->myHead = endHead->myHead->left;
    }else if(endHead->myHead->left->right == NULL){
        endHead->myHead->left->left = NewNode;
        NewNode->myHead = endHead->myHead->left;
    }else if (endHead->left == NULL)
    {
        endHead->left = NewNode;
        NewNode->myHead = endHead;
    }
    else if (endHead->right == NULL)
    {
        endHead->right = NewNode;
        NewNode->myHead = endHead;
    }
    endHead = NewNode;
    AdjustHeap();
}

HeapStruct *FindKey(HeapStruct *pHead, int value)
{
    if (pHead == NULL)
    {
        return NULL;
    }
    if (pHead->key == value)
    {
        return pHead;
    }
    HeapStruct *temp;
    temp = FindKey(pHead->left, value);
    if (temp != NULL)
    {
        return temp;
    }
    temp = FindKey(pHead->right, value);
    if (temp != NULL)
    {
        return temp;
    }
    return NULL;
}

void DelHeap(int a)
{
    if (Head == NULL)
    {
        return;
    }
    endHead = NULL;
    FindEnd(Head);

    HeapStruct *tempHeap = FindKey(Head, a);
    if (tempHeap != NULL && endHead != NULL) //find it
    {
        int tempInt = tempHeap->key;
        tempHeap->key = endHead->key;
        endHead->key = tempInt;

        if (endHead->myHead->left == endHead)
        {
            endHead->myHead->left = NULL;
        }
        if (endHead->myHead->right == endHead)
        {
            endHead->myHead->right = NULL;
        }

        delete endHead;
        endHead = NULL;
        HeapStruct *adjHeap = tempHeap;
        // up
        while (adjHeap->myHead != NULL && adjHeap->myHead->key > adjHeap->key)
        {
            tempInt = adjHeap->myHead->key;
            adjHeap->myHead->key = adjHeap->key;
            adjHeap->key = tempInt;
            adjHeap = adjHeap->myHead;
        }
        // down
        while (adjHeap->right != NULL && adjHeap->right->key < adjHeap->key)
        {
            tempInt = adjHeap->right->key;
            adjHeap->right->key = adjHeap->key;
            adjHeap->key = tempInt;
            adjHeap = adjHeap->right;
        }
        while (adjHeap->left != NULL && adjHeap->left->key < adjHeap->key)
        {
            tempInt = adjHeap->left->key;
            adjHeap->left->key = adjHeap->key;
            adjHeap->key = tempInt;
            adjHeap = adjHeap->left;
        }
    }
}

void QueryHeap(HeapStruct *phead)
{
    if (phead == NULL)
    {
        return;
    }
    bufForPrint[HeapDepth].push_back(phead->key);
    if (phead->left != NULL)
    {
        HeapDepth++;
        QueryHeap(phead->left);
        HeapDepth--;
    }
    if (phead->right != NULL)
    {
        HeapDepth++;
        QueryHeap(phead->right);
        HeapDepth--;
    }
}

void PrintAll()
{
    for (int i = 0; i < bufForPrint.size(); i++)
    {
        for (int j = 0; j < bufForPrint[i].size(); j++)
        {
            cout << bufForPrint[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char **args)
{

    int n, m, temp;
    string cmd;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        AddHeap(temp);
        RefreshDepth();
        QueryHeap(Head);
        PrintAll();
    }
    for (int i = 0; i < m; i++)
    {
        cin >> cmd >> temp;
        if (cmd == "add")
        {
            AddHeap(temp);
            RefreshDepth();
            QueryHeap(Head);
            PrintAll();
        }
        else if (cmd == "delete")
        {
            DelHeap(temp);
            RefreshDepth();
            QueryHeap(Head);
            PrintAll();
        }
    }
    QueryHeap(Head);
    return 0;
}