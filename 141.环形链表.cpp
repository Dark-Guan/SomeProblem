/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if( head == nullptr ){
            return false;
        }
        ListNode *first = head;
        ListNode *second = head;

        while(true){
            if(first->next == nullptr || second->next == nullptr){
                return false;
            }
            // 一个移动一步，一个移动两步
            first = first->next;
            if(second->next->next == nullptr){
                return false;
            }
            second = second->next->next;
            //  追上了
            if( first == second){
                return true;
            }
        }
    }
};
// @lc code=end

int main()
{
    ListNode list1(3);
    ListNode list2(2);
    ListNode list3(0);
    ListNode list4(-4);

    list1.next = &list2;
    list2.next = &list3;
    list3.next = &list4;
    list4.next = &list2;

    Solution solution;

    cout << solution.hasCycle(&list1) << endl;
}