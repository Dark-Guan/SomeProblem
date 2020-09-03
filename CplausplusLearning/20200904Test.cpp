

#include <iostream>
// 传递引用一定比传递指针效率低
// 函数不能返回

using namespace std;

void unique_ptr_test(){
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
    cout << __func__ << endl;
}

void TestInherit(){
    cout << "**************" << endl;
    cout << __func__ << endl;
    class X{
    
    public:
        X(){
            cout << "Call X()" << endl;
        }
        ~X(){
            cout << "Call ~X()" << endl;
        }
    };

    class Y : X{
    
    public:
        Y(){
            cout << "Call Y()" << endl;
        }
        ~Y(){
            cout << "Call ~Y()" << endl;
        }
    };

    Y y;
    cout << __func__ << endl;
    cout << "**************" << endl;
}


// what ?
void TestInherit1(){
    cout << "**************" << endl;
    cout << __func__ << endl;
    class A{
    public:
    private:
        void testFunc(){
            cout << "run A testFunc" << endl;
        }
    };

    class B: public A{
    public:
    private:
        void testFunc(){
            cout << "run A testFunc" << endl;
        }
    };

    class C : public B{
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

void TestInherit2(){
    cout << "**************" << endl;
    cout << __func__ << endl;
    class A{
    public:
        virtual void testFunc(){
            cout << "run A testFunc" << endl;
        }
    };

    class B: public A{
    public:
        void testFunc() override{
            cout << "run B testFunc" << endl;
        }
    };

    class C : public B{
    public:
       void testFunc(){
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

void TestInherit3(){
    cout << "**************" << endl;
    cout << __func__ << endl;

    class A{
    public:
        virtual void test();
    };   

    class B: public A{
    public:
        void test(){
            cout << "Run B Test" << endl;
        }
    };
    // A a; 
//     undefined reference to `vtable for TestInherit3()::A'
// collect2.exe: error: ld returned 1 exit status
    B b;
    b.test();
    cout << __func__ << endl;
    cout << "**************" << endl;
}


void TestInherit4(){
    cout << "**************" << endl;
    cout << __func__ << endl;

    class A{
    public:
        virtual void test(){
            cout << "Run A Test" << endl;
        }
        virtual ~A(){
            cout << "Run ~A()" << endl;
        }
    };   

    class B: public A{
    public:
        virtual void test(){
            cout << "Run B Test" << endl;
        }
        virtual ~B(){
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

class TestClass{
    public:
    void init(){

    }
};

// warning: reference to local variable
// 'obj' returned [-Wreturn-local-addr]
//      TestClass obj;
TestClass& MakeTestClass(){
    TestClass obj;
    obj.init();
    return obj;
}

// ok
TestClass MakeTestClass1(){
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
TestClass* MakeTestClass3(){
    TestClass obj;
    obj.init();
    return &obj;
}


int main(){
    unique_ptr_test();
    TestInherit();
    TestInherit1();
    TestInherit2();
    TestInherit3();
    TestInherit4();
    return 0;
}