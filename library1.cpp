#include <iostream>
#include <vector>
using namespace std;
static int book, user, librarian, reader;
int This;
int identity;

class Book
{
private:
    string code;
    string name;
    int price;
    int num;

public:
    /*Book(string c, string n, int p, int n1)
    {
        code = c;
        name = n;
        price = p;
        num = n1;
        book++;
    }*/
    Book() {}
    string Getcode() { return code; }
    string Getname1() { return name; }
    int Getprice() { return price; }
    int Getnum() { return num; }
    void Setcode(string c) { code = c; }
    void Setname(string n) { name = n; }
    void Setprice(int p) { price = p; }
    void Setnum(int n) { num = n; }
};
vector<Book> B;

class User
{
protected:
    string name;
    string key;
    bool IsAdmin, Islibrarian, Isreader;

public:
    User()
    {
        IsAdmin = 0;
        Islibrarian = 0;
        Isreader = 1;
    }
    string Getname() { return name; }
    string Getkey() { return key; }
    void Setname(string n) { name = n; }
    void Setkey(string k) { key = k; }
    void Setuseridentity(bool a, bool l, bool r)
    {
        IsAdmin = a;
        Islibrarian = l;
        Isreader = r;
    }
    void changekey()
    {
        string kk, key1, key2;
        cout << "请输入原密码：" << endl;
        cin >> kk;
        if (kk != key)
        {
            cout << "密码错误，修改失败！" << endl;
            return;
        }
        cout << "请输入新密码：" << endl;
        cin >> key1;
        cout << "请再次输入：" << endl;
        cin >> key2;
        if (key1 == key2)
        {
            Setkey(key1);
            cout << "修改成功！" << endl;
        }
        else
            cout << "输入不一致，修改失败！" << endl;
    }
    int Judge()
    {
        if (IsAdmin)
            return 1;
        if (Islibrarian)
            return 2;
        if (Isreader)
            return 3;
    }
};
vector<User> U;

class Log
{
public:
    bool Is_Login;
    void Signin()
    {
        User p;
        bool flag;
        string name1, key1, key2;
        cout << "请输入用户名：" << endl;
        cin >> name1;
        while (1)
        {
            flag = 0;
            for (int i = 0; i < user; ++i)
            {
                if (U[i].Getname() == name1)
                {
                    cout << "用户名已存在，请重新输入：" << endl;
                    flag = 1;
                }
            }
            if (flag)
                cin >> name1;
            else
                break;
        }
        while (1)
        {
            cout << "请输入密码：" << endl;
            cin >> key1;
            cout << "请再次输入密码：" << endl;
            cin >> key2;
            if (key1 != key2)
            {
                cout << "两次输入不一致，请重新输入：" << endl;
            }
            else
                break;
        }
        p.Setname(name1);
        p.Setkey(key1);
        p.Setuseridentity(0, 0, 1);
        user++;
        U.push_back(p);
    }
    void Login();
    /*{
        int flag;
        string name, key;
        cout << "请输入账号：" << endl;
        cin >> name;
        for (int i = 0; i < user; ++i)
        {
            if (name == U[i].Getname())
            {
                flag = i;
                break;
            }
            if (i == user - 1)
            {
                cout << "该用户不存在，登陆失败！" << endl;
                Is_Login = 0;
                return;
            }
        }
        cout << "请输入密码：" << endl;
        cin >> key;
        while (key != U[flag].Getkey())
        {
            cout << "密码错误，请重新输入：" << endl;
            cin >> key;
        }
        cout << "登陆成功" << endl;
        Is_Login = 1;
        identity = U[flag].Judge();
        if (identity == 2)
        {
            for (int i = 0; i < librarian; ++i)
            {
                if (Li[i].Getname() == U[flag].Getname())
                {
                    This = i;
                    break;
                }
            }
        }
        if (identity == 3)
        {
            for (int i = 0; i < reader; ++i)
            {
                if (R[i].Getname() == U[flag].Getname())
                {
                    This = i;
                    break;
                }
            }
        }
    }*/
} Lo;

class Librarian : public User, public Log
{
public:
    void sign()
    {
        Lo.Signin();
        cout << "注册成功！" << endl;
        librarian++;
        U.back().Setuseridentity(0, 1, 0);
    }
    void AddBook()
    {
        string a;
        int aa;
        char aaa;
        Book b;
        cout << "---------------添加图书---------------" << endl;
        while (1)
        {
            cout << "请输入编号：";
            cin >> a;
            b.Setcode(a);
            cout << "请输入书名：";
            cin >> a;
            b.Setname(a);
            cout << "请输入数量：";
            cin >> aa;
            b.Setnum(aa);
            cout << "请输入价格：";
            cin >> aa;
            b.Setprice(aa);
            book++;
            cout << "录入成功，是否继续录入？（y or n）" << endl;
            cin >> aaa;
            if (aaa == 'n')
            {
                cout << "结束录入。" << endl;
                break;
            }
        }
    }
    void DeleBook()
    {
        string a;
        cout << "---------------删除图书---------------" << endl;
        char c;
        if (!book)
            cout << "目前无图书，请先添加。" << endl;
        else
        {
            cout << "请输入图书编号：";
            cin >> a;
            int i;
            for (i = 0; i < book; ++i)
            {
                if (B[i].Getcode() == a)
                {
                    cout << "已经找到该图书，其名称为："
                         << "《" << B[i].Getname1() << "》"
                         << "，确定要删除吗？（y or n）" << endl;
                    cin >> c;
                    break;
                }
                if (i == book - 1)
                {
                    cout << "未找到该编号对应的图书，请检查输入是否有误。" << endl;
                    return;
                }
            }
            if (c == 'y')
            {
                for (int j = i; j < book - 1; ++j)
                {
                    B[j] = B[j + 1];
                }
                B.pop_back();
                book--;
                cout << "删除成功！" << endl;
            }
            else
            {
                cout << "未删除。" << endl;
            }
        }
    }
    void AlterBook() //修改图书
    {
        string a;
        cout << "---------------修改图书---------------" << endl;
        if (!book)
        {
            cout << "目前无图书，请先添加。" << endl;
            return;
        }
        cout << "请输入编号：";
        cin >> a;
        int find;
        int b;
        char c;
        for (int i = 0; i < book; ++i)
        {
            if (B[i].Getcode() == a)
            {
                cout << "已经找到该图书，其名称为："
                     << "《" << B[i].Getname1() << "》"
                     << "，确定要修改吗？（y or n）" << endl;
                find = i;
                cin >> c;
                break;
            }
            if (i == book - 1)
            {
                cout << "未找到该编号对应的图书，请检查输入是否有误。" << endl;
                return;
            }
        }
        cout << "请选择修改项:" << endl;
        cout << "1-修改编号" << endl;
        cout << "2-修改书名" << endl;
        cout << "3-修改数量" << endl;
        cout << "4-修改单价" << endl;
        cout << "0-退出修改" << endl;
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            while (1)
            {
                cout << "请输入修改后的编号：" << endl;
                cin >> a;
                for (int i = 0; i < book; ++i)
                {
                    if (B[i].Getcode() == a)
                    {
                        cout << "该编号已存在！" << endl;
                        break;
                    }
                    if (i == book - 1)
                    {
                        B[find].Setcode(a);
                        cout << "修改完成！" << endl;
                    }
                }
            }
            break;
        }
        case 2:
        {
            cout << "请输入修改后的书名：" << endl;
            cin >> a;
            B[find].Setname(a);
            cout << "修改完成！" << endl;
            break;
        }
        case 3:
        {
            cout << "请输入修改后的数量：";
            cin >> b;
            B[find].Setnum(b);
            cout << "修改完成！" << endl;
            break;
        }
        case 4:
        {
            cout << "请输入修改后的单价：";
            cin >> b;
            B[find].Setprice(b);
            cout << "修改完成！" << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "请输入正确数字：";
        }
    }
    void FindBook() //查血图书
    {
        cout << "-------查询图书-------" << endl;
        cout << "请输入图书编号：";
        string a;
        int find;
        cin >> a;
        for (int i = 0; i < book; ++i)
        {
            if (B[i].Getcode() == a)
            {
                cout << "已经找到该图书，其名称为："
                     << "《" << B[i].Getname1() << "》"
                     << "，单价是：" << B[i].Getprice() << ",数量有："
                     << B[i].Getnum() << endl;
                find = i;
                break;
            }
            if (i == book - 1)
            {
                cout << "未找到该编号对应的图书，请检查输入是否有误。" << endl;
                return;
            }
        }
    }
    void AddupBook() //统计图书
    {
        cout << "现共有" << book << "本书。" << endl;
        for (int i = 0; i < book; ++i)
        {
            cout << B[i].Getcode() << ' ' << B[i].Getname1() << endl;
        }
    }
};
vector<Librarian> Li;

class Reader : public User, public Log, public Book
{
private:
    Book a[100];

public:
    void sign()
    {
        Lo.Signin();
        cout << "注册成功！" << endl;
        U.back().Setuseridentity(0, 0, 1);
        reader++;
    }
    void LendBook()
    {
        cout << "请输入要借阅图书的编号：";
        string a;
        int find;
        char c;
        cin >> a;
        for (int i = 0; i < book; ++i)
        {
            if (B[i].Getcode() == a)
            {
                cout << "已经找到该图书，其名称为："
                     << "《" << B[i].Getname1() << "》"
                     << "，确定要借阅吗？（y or n）" << endl;
                find = i;
                cin >> c;
                break;
            }
            if (i == book - 1)
            {
                cout << "未找到该编号对应的图书，请检查输入是否有误。" << endl;
                return;
            }
        }
        if (B[find].Getnum() == 0)
        {
            cout << "该书无库存！" << endl;
            return;
        }
        B[find].Setnum(B[find].Getnum() - 1);
        cout << "借阅成功！" << endl;
    }
    void ReturnBook()
    {
        cout << "请输入归还图书的编号：";
        string a;
        cin >> a;
        int find;
        char c;
        for (int i = 0; i < book; ++i)
        {
            if (B[i].Getcode() == a)
            {
                cout << "已经找到该图书，其名称为："
                     << "《" << B[i].Getname1() << "》"
                     << "，确定要归还吗？（y or n）" << endl;
                find = i;
                cin >> c;
                break;
            }
            if (i == book - 1)
            {
                cout << "未找到该编号对应的图书，请检查输入是否有误。" << endl;
                return;
            }
        }
        if (c == 'y')
        {
            B[find].Setnum(B[find].Getnum() + 1);
            cout << "已归还！" << endl;
        }
        else
        {
            cout << "未归还！" << endl;
        }
    }
    void display()
    {
        for (int i = 0; i < book; ++i)
        {
            cout << B[i].Getcode() << ' ' << B[i].Getname1() << ' ' << B[i].Getnum() << endl;
        }
    }
};
vector<Reader> R;
class Admin : public User, public Log
{
public:
    Admin()
    {
        IsAdmin = 1;
        Islibrarian = 0;
        Isreader = 0;
    }
    void AddReader()
    {
        R[reader].sign();
    }
    void DeleReader()
    {
        string a;
        char c;
        int find;
        cout << "请输入要删除的用户名：";
        cin >> a;
        for (int i = 0; i < user; ++i)
        {
            if (U[i].Getname() == a)
            {
                cout << "已找到该用户，要删除吗？（y or n）";
                cin >> c;
                find = i;
                break;
            }
            if (i == user - 1)
            {
                cout << "该用户未注册！" << endl;
                return;
            }
        }
        for (int i = find; i < user - 1; ++i)
        {
            U[i] = U[i + 1];
        }
        user--;
        U.pop_back();
        cout << "删除成功！" << endl;
    }
} A;

void display1()
{
    cout << "|图书管理员:L   密码:8  |  系统管理员:A   密码:8|" << endl;
    cout << "I—————————————图书管理系统—————————————————I" << endl;
    cout << "I—————————————①------注册------————————————I" << endl;
    cout << "I—————————————②------登陆------————————————I" << endl;
    cout << "I—————————————③------退出------————————————I" << endl;
}

void display2() //读者
{
    cout << "①-------查看图书" << endl;
    cout << "②-------借书" << endl;
    cout << "③-------还书" << endl;
    cout << "⑤-------修改密码" << endl;
    cout << "⑥-------退出" << endl;
}

void display3() //图书管理员
{
    cout << "①-------增加图书" << endl;
    cout << "②-------修改图书" << endl;
    cout << "③-------删除图书" << endl;
    cout << "④-------查询图书" << endl;
    cout << "⑤-------统计图书" << endl;
    cout << "⑥-------修改密码" << endl;
    cout << "⑦-------退出" << endl;
}

void display4() //系统管理员
{
    cout << "①-------增加读者" << endl;
    cout << "②-------删除读者" << endl;
    /*cout << "③-------增加图书管理员" << endl;
    cout << "④-------删除图书管理员" << endl;
    cout << "⑤-------读者权限修改" << endl;
    cout << "⑥-------图书管理员权限修改" << endl;
    cout << "⑦-------修改用户密码" << endl;*/
    cout << "⑧-------修改密码" << endl;
    cout << "⑨-------退出" << endl;
}
void Log::Login()
{
    int flag;
    string name, key;
    cout << "请输入账号：" << endl;
    cin >> name;
    for (int i = 0; i < user; ++i)
    {
        if (name == U[i].Getname())
        {
            flag = i;
            break;
        }
        if (i == user - 1)
        {
            cout << "该用户不存在，登陆失败！" << endl;
            Is_Login = 0;
            return;
        }
    }
    cout << "请输入密码：" << endl;
    cin >> key;
    while (key != U[flag].Getkey())
    {
        cout << "密码错误，请重新输入：" << endl;
        cin >> key;
    }
    cout << "登陆成功" << endl;
    Is_Login = 1;
    identity = U[flag].Judge();
    if (identity == 2)
    {
        for (int i = 0; i < librarian; ++i)
        {
            if (Li[i].Getname() == U[flag].Getname())
            {
                This = i;
                break;
            }
        }
    }
    if (identity == 3)
    {
        for (int i = 0; i < reader; ++i)
        {
            if (R[i].Getname() == U[flag].Getname())
            {
                This = i;
                break;
            }
        }
    }
}
void start()
{
    Librarian a;
    a.Setname("L");
    a.Setkey("8");
    a.Setuseridentity(0, 1, 0);
    Li.push_back(a);
    librarian++;
    user++;
    A.Setname("A");
    A.Setkey("8");
    A.Setuseridentity(1, 0, 0);
    user++;
    U.push_back(a);
    U.push_back(A);
}
int main()
{
    start();
    while (1)
    {
        display1();
        int a;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "             读者注册" << endl;
            Reader r;
            r.sign();
            R.push_back(r);
        }
        case 2:
        {
            cout << "             登  陆" << endl;
            Lo.Login();
            if (!Lo.Is_Login)
                continue;
            if (identity == 1)
            {
                int n = 1;
                while (n)
                {
                    display4();
                    int b;
                    cin >> b;
                    switch (b)
                    {
                    case 1: //增加读者
                    {
                        A.AddReader();
                        break;
                    }
                    case 2: //删除读者
                    {
                        A.DeleReader();
                        break;
                    }
                    /*case 3: //增加图书管理员
                    {
                        A[c.number].Librarian_Add(U, L);
                        break;
                    }
                    case 4: //增加图书管理员
                    {
                        A[c.number].Librarian_Dele(U, L);
                        break;
                    }
                    case 5: //读者权限修改
                    {
                        A[c.number].Reader_Alter(R, U, A, L);
                        break;
                    }
                    case 6: //图书管理员权限修改
                    {
                        A[c.number].Librarian_Alter(L, U, A, R);
                        break;
                    }
                    case 7: //修改用户密码
                    {
                        A[c.number].User_keychange(U);
                        break;
                    }*/
                    case 8: //修改密码
                    {
                        A.changekey();
                        break;
                    }
                    default:
                        n = 0;
                        break;
                    }
                }
            }
            else if (identity == 2)
            {
                int n = 1;
                while (n)
                {
                    display3();
                    int b;
                    cin >> b;
                    switch (b)
                    {
                    case 1:
                    {
                        Li[This].AddBook();
                        break;
                    }
                    case 2:
                    {
                        Li[This].AlterBook();
                        break;
                    }
                    case 3:
                    {
                        Li[This].DeleBook();
                        break;
                    }
                    case 4:
                    {
                        Li[This].FindBook();
                        break;
                    }
                    case 5:
                    {
                        Li[This].AddupBook();
                        break;
                    }
                    case 6:
                    {
                        Li[This].changekey();
                        break;
                    }
                    default:
                        n = 0;
                    }
                }
            }
            else if (identity == 3)
            {
                int n = 1;
                while (n)
                {
                    display2();
                    int b;
                    cin >> b;
                    switch (b)
                    {
                    case 1: //书本展示
                    {
                        R[This].display();
                        break;
                    }
                    case 2: //借书
                    {
                        R[This].LendBook();
                        break;
                    }
                    case 3: //还书
                    {
                        R[This].ReturnBook();
                        break;
                    }

                    case 4: //修改密码
                    {
                        R[This].changekey();
                        break;
                    }
                    default:
                        n = 0;
                    }
                }
            }
            else
                break;
            break;
        }
        case 3:
        {
            cout << "             系统已退出" << endl;
            return 0;
            break;
        }
        default:
            break;
        }
        cin.get(); //吸收回车符
        cout << "按回车键返回主界面" << endl;
        cin.get();
    }
    system("pause");
    return 0;
}