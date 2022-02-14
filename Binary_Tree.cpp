#include <iostream>
#include <queue>
#define MAX_TREE_SIZE 100
#define TREEINCREMENT 10
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
typedef char ElemType;
typedef int Status;
using namespace std;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode;

class BiTree
{
private:
    BiTNode *T;
    Status Create(BiTNode *&t)
    {
        ElemType ch;
        cin >> ch;
        if (ch == '#')
        {
            t = NULL;
        }
        else
        {
            t = new BiTNode;
            t->data = ch;
            Create(t->lchild);
            Create(t->rchild);
        }
    }

    Status PreOder(BiTNode *t)
    {
        if (t == NULL)
            return NULL;
        else
        {
            Visit(t);
            PreOder(t->lchild);
            PreOder(t->rchild);
        }
    }

    Status InOrder(BiTNode *t)
    {
        if (t == NULL)
            return NULL;
        else
        {
            InOrder(t->lchild);
            Visit(t);
            InOrder(t->rchild);
        }
    }

    Status PostOrder(BiTNode *t)
    {
        if (t == NULL)
            return NULL;
        else
        {
            PostOrder(t->lchild);
            PostOrder(t->rchild);
            Visit(t);
        }
    }

    void Visit(BiTNode *t)
    {
        cout << t->data << ' ';
    }

public:
    Status CreateBiTree() //按先序遍历输入二叉树中各结点的值，‘#’表示空格
    {
        Create(T);
    }

    Status PreOrderTraverse() //先序遍历二叉树
    {
        PreOder(T);
    }

    Status InOrderTraverse() //中序遍历二叉树
    {
        InOrder(T);
    }

    Status PostOrderTraverse() //后序遍历二叉树
    {
        PostOrder(T);
    }

    Status LevelOrderTraverse() //层序遍历
    {
        queue<BiTNode *> q;
        if (T != NULL)
            q.push(T);
        while (!q.empty())
        {
            Visit(q.front());
            if (q.front()->lchild)
                q.push(q.front()->lchild);
            if (q.front()->rchild)
                q.push(q.front()->rchild);
            q.pop();
        }
    }
};

int main()
{
    BiTree B;
    B.CreateBiTree();
    B.LevelOrderTraverse();
    system("pause");
}