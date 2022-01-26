#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ElemType int
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
typedef int Status;

class SqStack //顺序栈
{
private:
    ElemType *top;
    ElemType *base;
    int stacksize;

public:
    Status InitStack()
    {
        base = new ElemType[STACK_INIT_SIZE];
        if (!base)
            return ERROR;
        top = base;
        stacksize = STACK_INIT_SIZE;
        return OK;
    }

    Status GetTop(ElemType &e)
    {
        if (top == base)
            return ERROR;
        e = *(top - 1);
        return OK;
    }

    Status Push(ElemType e)
    {
        if (top - base >= stacksize)
        {
            base = (ElemType *)realloc(base, (stacksize + STACKINCREMENT) * sizeof(ElemType));
            if (!base)
                return ERROR;
            top = base + stacksize;
            stacksize += STACKINCREMENT;
        }
        *top = e;
        top++;
        return OK;
    }

    Status Pop(ElemType &e)
    {
        if (top == base)
            return ERROR;
        e = *--top;
        return OK;
    }

    Status DestoryStack()
    {
        while (top)
        {
            delete top;
            top--;
        }
        stacksize = 0;
        return OK;
    }

    Status ClearStack()
    {
        base = NULL;
        top = base;
    }

    Status StackEmpty()
    {
        if (top == base)
            return TRUE;
        else
            return FALSE;
    }
    int StackLength()
    {
        return (top - base);
    }
};

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    struct LNode *prior;
} LNode;

class LinkStack
{
private:
    LNode *top, *base;

public:
    LinkStack()
    {
        base = new LNode;
        base->next = NULL;
        base->prior = NULL;
        base->next = new LNode;
        base->next->prior = base;
        top = base;
    }

    Status GetTop(ElemType &e)
    {
        if (top == base)
            return ERROR;
        e = top->data;
    }

    Status Push(ElemType e)
    {
        top->data = e;
        top->next = new LNode;
        top->next->prior = top;
        top = top->next;
    }

    Status Pop(ElemType &e)
    {
        top = top->prior;
        delete top->next;
        e = top->data;
    }

    Status DestoryStack()
    {
        while (top)
        {
            delete top;
            top = top->prior;
        }
    }

    Status ClearStack()
    {
        base = NULL;
        top = base;
        return OK;
    }

    Status StackEmpty()
    {
        if (top == base)
            return TRUE;
        else
            return FALSE;
    }
    int StackLength()
    {
        int i = 0;
        LNode *p = base;
        while (p != top)
        {
            p = p->next;
            i++;
        }
        return i;
    }
};