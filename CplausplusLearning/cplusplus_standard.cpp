
#include <iostream>
#include <vector>
#include <set>

int main()
{
    // std::optional; ? 这是一个什么 

    // func(void * )入参替代
    // func(std::variant<Message, Object> &data) 表示可能的多种类型
    //  func(Base &base)以及 基类调用的方法；
    // 如果是字节流 可以考虑 用func(std::vector<uint8_t>& buffer)
    
    
    std::vector<int> numbers = {0, 0, 5};

    std::set<std::string> myset;
    auto [iter, success] = myset.insert("Hello"); // C++17 Structured binding 结构化绑定
    // insert 返回的是一个 std::pair



    return 0;
}