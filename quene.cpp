#include <iostream>
using namespace std;
#define Quene_INIT_SIZE 100
#define QUENEINCREMENT 10
#define ElemType int
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
typedef int Status;

typedef struct QNode
{
    ElemType data;
    QNode *next;
} QNode;

class LinkQuene
{
private:
    QNode *front; //队头指针
    QNode *rear;  //队尾指针
public:
    Status InitQuene()
    {
        front = rear = new QNode;
        if (!front)
            return ERROR;
        front->next = NULL;
        return OK;
    }

    Status DestroyQuene()
    {
        while (front)
        {
            rear = front->next;
            delete front;
            front = rear;
        }
        return OK;
    }

    Status ClearQuene()
    {
        front = rear;
        rear = NULL;
        return OK;
    }

    Status QueneEmpty()
    {
        if (rear == front)
            return TRUE;
        else
            return FALSE;
    }

    int QueneLength()
    {
        QNode *p = front;
        int i = 0;
        while (p != rear)
        {
            i++;
            p = p->next;
        }
        return i;
    }

    Status GetHead(ElemType &e)
    {
        if (rear == front)
            return ERROR;
        e = front->data;
        return OK;
    }

    Status EnQuene(ElemType e)
    {
        rear->next = new QNode;
        rear->data = e;
        rear = rear->next;
        rear->next = NULL;
    }

    Status DeQuene(ElemType &e)
    {
        if (rear == front)
            return ERROR;
        e = front->data;
        QNode *p = front;
        front = front->next;
        delete p;
    }
};

class SqQuene
{
private:
    int front;
    int rear;
    ElemType *data;
    int quenesize;

public:
    Status InitQuene()
    {
        data = new ElemType[Quene_INIT_SIZE];
        quenesize = Quene_INIT_SIZE;
        if (!data)
            return ERROR;
        front = rear = 0;
        return OK;
    }

    Status DestroyQuene()
    {
        delete[] data;
        return OK;
    }

    Status ClearQuene()
    {
        data = NULL;
        return OK;
    }

    Status QueneEmpty()
    {
        if (rear == front)
            return TRUE;
        else
            return FALSE;
    }

    int QueneLength()
    {
        return (rear - front);
    }

    Status GetHead(ElemType &e)
    {
        e = data[rear - 1];
        return OK;
    }

    Status EnQuene(ElemType e)
    {
        if (rear - front >= quenesize)
        {
            data = (ElemType *)realloc(data, (Quene_INIT_SIZE + QUENEINCREMENT) * sizeof(ElemType));
            if (!data)
                return ERROR;
            quenesize += QUENEINCREMENT;
        }
        data[rear] = e;
        rear++;
        return OK;
    }

    Status DeQuene(ElemType &e)
    {
        if (rear == front)
            return ERROR;
        e = data[front];
        front++;
        return OK;
    }
};