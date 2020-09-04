

#include <iostream>
#include <cstring>
// 传递引用一定比传递指针效率低
// 函数不能返回

using namespace std;

void unique_ptr_test()
{
    // get()  release() reset()
    // = 赋值之后会销毁对象

    cout << __func__ << endl;
    // std::auto_ptr<int> a;
    // int b = 10;
    // b = a;
    // cout << *a << endl;

    // unique_ptr<int> unique_ptr1(new int(10));
    // cout << *unique_ptr1 << endl;

    // a = unique_ptr1.release();

    // std::make_unique 函数可以在构造函数中使用
    cout << __func__ << endl;
}

void TestInherit()
{
    cout << "**************" << endl;
    cout << __func__ << endl;
    class X
    {

    public:
        X()
        {
            cout << "Call X()" << endl;
        }
        ~X()
        {
            cout << "Call ~X()" << endl;
        }
    };

    class Y : X
    {

    public:
        Y()
        {
            cout << "Call Y()" << endl;
        }
        ~Y()
        {
            cout << "Call ~Y()" << endl;
        }
    };

    Y y;
    cout << __func__ << endl;
    cout << "**************" << endl;
}

// what ?
void TestInherit1()
{
    cout << "**************" << endl;
    cout << __func__ << endl;
    class A
    {
    public:
    private:
        void testFunc()
        {
            cout << "run A testFunc" << endl;
        }
    };

    class B : public A
    {
    public:
    private:
        void testFunc()
        {
            cout << "run A testFunc" << endl;
        }
    };

    class C : public B
    {
    public:
    };
    C c;
    // c.testFunc(); // wrong within this context B::testFunc()' is private
    // c.A::testFunc(); // within this context
    // c.B::testFunc();
    // A::c.testFunc();
    // B::c.testFunc();
    cout << __func__ << endl;
    cout << "**************" << endl;
}

void TestInherit2()
{
    cout << "**************" << endl;
    cout << __func__ << endl;
    class A
    {
    public:
        virtual void testFunc()
        {
            cout << "run A testFunc" << endl;
        }
    };

    class B : public A
    {
    public:
        void testFunc() override
        {
            cout << "run B testFunc" << endl;
        }
    };

    class C : public B
    {
    public:
        void testFunc()
        {
            cout << "run C testFunc" << endl;
        }
    };
    cout << "Size A " << sizeof(A) << endl;
    cout << "Size B " << sizeof(B) << endl;
    cout << "Size C " << sizeof(C) << endl;

    C *c = new C();
    c->testFunc();
    B *b = c;
    b->testFunc();
    A *a = c;
    c->testFunc();

    cout << __func__ << endl;
    cout << "**************" << endl;
}

void TestInherit3()
{
    cout << "**************" << endl;
    cout << __func__ << endl;

    class A
    {
    public:
        virtual void test();
    };

    class B : public A
    {
    public:
        void test()
        {
            cout << "Run B Test" << endl;
        }
    };
    // A a;
    //     undefined reference to `vtable for TestInherit3()::A'
    // collect2.exe: error: ld returned 1 exit status
    B b;
    b.test();
    //  cannot convert 'TestInherit3()::B' to 'TestInherit3()::A*' in initialization
    // A *a = b; //纯虚函数不能转换成功
    // a->test();
    cout << __func__ << endl;
    cout << "**************" << endl;
}

void TestInherit4()
{
    cout << "**************" << endl;
    cout << __func__ << endl;

    class A
    {
    public:
        virtual void test()
        {
            cout << "Run A Test" << endl;
        }
        virtual ~A()
        {
            cout << "Run ~A()" << endl;
        }
    };

    class B : public A
    {
    public:
        virtual void test()
        {
            cout << "Run B Test" << endl;
        }
        virtual ~B()
        {
            cout << "Run ~B" << endl;
        }
    };
    A *a = new B();
    B *b = new B();
    a->test();
    b->test();
    delete a;
    delete b;
    cout << __func__ << endl;
    cout << "**************" << endl;
}

void TestInherit5()
{
    cout << "**************" << endl;
    cout << __func__ << endl;
    class X
    {

    public:
        explicit X()
        {
            cout << "Call X()" << endl;
        }
        // only declarations of constructors can be 'explicit'
        //  explicit ~X()
        // explicit ~X()
        // {
        //     cout << "Call ~X()" << endl;
        // }
//  only declarations of constructors can be 'explicit'
//          explicit void test(){
        // explicit void test(){

        // }
    };

    class Y : X
    {

    public:
        Y()
        {
            cout << "Call Y()" << endl;
        }
        ~Y()
        {
            cout << "Call ~Y()" << endl;
        }
    };

    Y y;
    cout << __func__ << endl;
    cout << "**************" << endl;
}

class TestClass
{
public:
    void init()
    {
    }
};

// warning: reference to local variable
// 'obj' returned [-Wreturn-local-addr]
//      TestClass obj;
// TestClass& MakeTestClass(){
//     TestClass obj;
//     obj.init();
//     return obj;
// }

// ok
TestClass MakeTestClass1()
{
    TestClass obj;
    obj.init();
    return obj;
}

// error: invalid initialization of
// non-const reference of type 'TestClass&'
// from an rvalue of type 'TestClass*'
//      return &obj;
// TestClass& MakeTestClass2(){
//     TestClass obj;
//     obj.init();
//     return &obj;
// }

// warning: address of local variable 'obj' returned
// [-Wreturn-local-addr]
//      TestClass obj;
// TestClass* MakeTestClass3(){
//     TestClass obj;
//     obj.init();
//     return &obj;
// }

// what X64 架构下可以使用 RDI RSI 寄存器 传递两个整形 传递参数 ？
// 栈中的区域， 局部变量去，参数，返回地址
int sum(int x, int y)
{
    return x + y;
}

int caller()
{

    int x = 10;
    int y = 10;
    int r = sum(x, y);
    cout << "r result " << r << endl;
}

// 下面那个不太好 ?
struct Student
{
    int id;
    int age;
    bool isMale;
};

class VirtualMachine
{

public:
    VirtualMachine(int id) : m_id(id)
    {
    }

private:
    int m_id;
    int m_load{0};
};

// 哈希14个桶 哈希 函数 h（key） = key % 11
// 18 37 55 61 79 再 39 位于那一个桶？

// 适用于std::sort 和不适合 的容器；
// 能 vector deque 属于 Random Access 可以
// stack queue priority_queue 能不能？
// set map 是不行？

// C++17 互斥锁 条件锁 自旋锁 读写锁 递归锁
//  share_mutex 和 mutex 更好的性能优势
// 原子锁适合长时间
// 自旋锁

// 函数对象
// 函数对象比函数指针的性能会下降
// 肯能在几次调研之间保持状态
// operater() 声明为 inline 可建议将函数对象进行内联；

// what ?
// void send(std::function<void(int result) pfn){

// }

class MySession
{
public:
    MySession(int id) : mySessionId(id)
    {
    }

private:
    int mySessionId;
};

void TestFucntion()
{
    MySession session(3);
    // auto pfn = [session](int result) -> void {

    // };
    // auto pfn = [=](int result) -> void {

    // };
    //  auto pfn = [&](int result) -> void {

    // };

    // senf(pfn);
}


// 下列函数的问题 存在的问题

void test(char * str){
    cout << "run test" << endl;
    const int BUF_SIZE = 1024;
    char buf[BUF_SIZE];
    snprintf(buf,BUF_SIZE, "/usr/bin/%s", str);
    strcpy(buf,str);
    printf(str);
    // ret = exel(str);
    printf("\r\n");
    /*
    momery_leak
    buffer_overflow
    path_traversal
    format_string_attack
    command_injection
    resurce_injuection
    */
   cout << "end of test" << endl;
}


// TMG备案问题
// 工具不支持编译选项可以发起备案申请
// 安全编译选择实施上有问题，需要走TMG

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {   
        test(argv[i]);
        cout << "Parameter  " << i << " = " << argv[i] << endl;
    }

    unique_ptr_test();
    TestInherit();
    TestInherit1();
    TestInherit2();
    TestInherit3();
    TestInherit4();
    TestInherit5();

    caller(); // 看一下栈的分布；
    return 0;
}