#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int KeyType;

//以下各排序方法均为非递减顺序

typedef struct
{
    KeyType key;

} RedType;

class SqList
{
private:
    RedType r[MAXSIZE + 1]; //r[0]闲置或用作哨兵单元
    int length;

    void ShellInsert(int dk)
    {
        int i, j;
        for (i = dk + 1; i < length; ++i)
        {
            if (r[i].key < r[i - dk].key)
            {
                r[0] = r[i];
                for (j = i - dk; j > 0 && r[0].key < r[j].key; j -= dk)
                {
                    r[j + dk] = r[j];
                }
                r[j + dk] = r[0];
            }
        }
    }

    int Partition(int low, int high) //一趟快排
    {
        r[0] = r[low];
        int pivotkey = r[0].key;
        while (low < high)
        {
            while (low < high && r[high].key >= pivotkey)
                --high;
            r[low] = r[high];
            while (low < high && r[low].key <= pivotkey)
                ++low;
            r[high] = r[low];
        }
        r[low] = r[0];
        return low;
    }

    void QSort(int low, int high)
    {
        if (low < high)
        {
            int pivotloc = Partition(low, high);
            QSort(low, pivotloc - 1);
            QSort(pivotloc + 1, high);
        }
    }

    void HeapAdjust(int s, int m)
    {
        RedType rc = r[s];
        int j;
        for (j = 2 * s; j <= m; j *= 2)
        {
            if (j < m && r[j].key < r[j + 1].key)
                ++j;
            if (rc.key > r[j].key)
                break;
            r[s] = r[j];
            s = j;
        }
        r[s] = rc;
    }

public:
    SqList()
    {
        cout << "输入元素个数及各元素：" << endl;
        int n;
        cin >> n;
        while (n > MAXSIZE)
        {
            cout << "个数过大，请保证其小于100" << endl;
            cout << "重新输入：" << endl;
            cin >> n;
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> r[i].key;
        }
        length = n;
    }

    void print()
    {
        for (int i = 1; i <= length; ++i)
            cout << r[i].key << ' ';
        cout << endl;
    }

    void InsertSort() //直接插入排序
    {
        int j;
        for (int i = 2; i <= length; ++i)
        {
            if (r[i].key < r[i - 1].key)
            {
                r[0] = r[i];
                r[i] = r[i - 1];
                for (j = i - 2; r[0].key < r[j].key; --j)
                {
                    r[j + 1] = r[j];
                }
                r[j + 1] = r[0];
            }
        }
    }

    void BInsertSort() //折半插入排序
    {
        int i, j, low, high, m;
        for (i = 2; i <= length; ++i)
        {
            r[0] = r[i];
            low = 1;
            high = i - 1;
            while (low <= high)
            {
                m = (low + high) / 2;
                if (r[0].key < r[m].key)
                    high = m - 1;
                else
                    low = m + 1;
            }
            for (j = i - 1; j >= high + 1; --j)
            {
                r[j + 1] = r[j];
            }
            r[high + 1] = r[0];
        }
    }

    void ShellSort(int dlta[], int t)
    {
        for (int k = 0; k < t; ++k)
        {
            ShellInsert(dlta[k]);
        }
    }

    void QuickSort()
    {
        QSort(1, length);
    }

    void HeapSort()
    {
        RedType temp;
        for (int i = length / 2; i > 0; --i)
            HeapAdjust(i, length);
        for (int i = length; i > 1; --i)
        {
            temp = r[1];
            r[1] = r[i];
            r[i] = temp;
            HeapAdjust(1, i - 1);
        }
    }
};

int main()
{
    int dlta[] = {5, 3, 1};
    SqList S;
    //S.ShellSort(dlta, sizeof(dlta) / 4);
    S.HeapSort();
    S.print();
    system("pause");
}