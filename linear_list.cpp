#include <iostream>
#define LIST_INIT_SIZE 1000
#define LISTINCREMENT 10
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
using namespace std;

typedef class SqList
{
private:
    ElemType *elem;
    int length;
    int listsize;

public:
    Status InitList() //构造一个空的线性表L
    {
        elem = new ElemType;
        if (!elem)
            return ERROR;
        length = 0;
        listsize = LIST_INIT_SIZE;
        return OK;
    }
    Status DestroyList() //销毁线性表
    {
        if (elem)
            delete elem;
        elem = NULL;
        listsize = 0;
        length = 0;
        return OK;
    }
    Status ClearList() //置为空表
    {
        length = 0;
    }
    Status ListEmpty() //判空
    {
        if (!length)
            return TRUE;
        else
            return FALSE;
    }
    int ListLength()
    {
        return length;
    }
    Status GetElem(ElemType &e, int i) //用e返回第i个元素
    {
        if (i <= length && i >= 1)
        {
            e = elem[i - 1];
            return OK;
        }
        else
            return ERROR;
    }
    int LocateElem(ElemType e) //返回第一个与e相等的元素位序
    {
        int i = 0;
        for (i = 0; i < length; ++i)
        {
            if (e == elem[i])
                return i + 1;
        }
        return FALSE;
    }
    Status PriorElem(ElemType cur_e, ElemType &pre_e)
    {
        if (cur_e == elem[0])
            return ERROR;
        for (int i = 1; i < length; ++i)
        {
            if (cur_e == elem[i])
            {
                pre_e = elem[i];
                return OK;
            }
        }
        return ERROR;
    }
    Status NextElem(ElemType cur_e, ElemType &next_e)
    {
        if (cur_e == elem[length - 1])
            return ERROR;
        for (int i = 0; i < length - 1; ++i)
        {
            if (cur_e == elem[i])
            {
                next_e = elem[i];
                return OK;
            }
        }
        return ERROR;
    }
    Status ListInsert(int i, ElemType e)
    {
        if (i < 1 || i > length + 1)
            return ERROR;
        if (length == LIST_INIT_SIZE)
            return ERROR;
        for (int j = length - 1; j >= i - 1; --j)
        {
            elem[j + 1] = elem[j];
        }
        elem[i - 1] = e;
        length++;
        return OK;
    }
    Status ListDelete(int i, ElemType &e)
    {
        if (i < 1 || i > length + 1)
            return ERROR;
        e = elem[i - 1];
        if (i < length)
            for (int j = i - 1; j < length - 1; ++j)
                elem[j] = elem[j + 1];
        length--;
        return OK;
    }
    Status ListTraverse() {}
    void Union(SqList Lb) //将在Lb中但不在该线性表中的元素插入到该线性表
    {
        int e;
        for (int i = 1; i <= Lb.length; ++i)
        {
            Lb.GetElem(e, i);
            if (!LocateElem(e))
                ListInsert(++length, e);
        }
    }
} SqList;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode;

class LinkList
{
private:
    LNode *head;
    LNode *tail;

public:
    LinkList()
    {
        head = new LNode;
        head->next = NULL;
        tail = head;
    }

    void HeadCreateList(int n) //头插法将n个元素插入
    {
        LNode *p = head;
        LNode *temp;
        temp = new LNode;
        cin >> temp->data;
        temp->next = p->next;
        p->next = temp;
        tail = temp;
        for (int i = 1; i < n; ++i)
        {
            temp = new LNode;
            cin >> temp->data;
            temp->next = p->next;
            p->next = temp;
        }
    }

    void TailCreateList(int n) //尾插法将n个元素插入
    {
        LNode *p = head;
        LNode *temp;
        for (int i = 0; i < n; ++i)
        {
            temp = new LNode;
            cin >> temp->data;
            temp = p->next;
            p = temp;
        }
        tail = p;
        p->next = NULL;
    }

    Status Insert(int i, ElemType e) //在位置i处插入元素e
    {
        LNode *temp = head;
        int j = 0;
        while (temp && j < i - 1)
        {
            temp = temp->next;
            j++;
        }
        if (!temp || j > i - 1)
            return ERROR;
        else
        {
            LNode *p;
            p = new LNode;
            p->data = e;
            p->next = temp->next;
            temp->next = p;
        }
    }
};