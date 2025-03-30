/*
本次笔记仅作为刷题中吃的大亏，由于虚拟头节点的问题，多次报错     runtime error: member access within null pointer of type 'ListNode' 
(solution.cpp)SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:28:21

这段错误表示的是访问空指针成员，在接下来的两题中均犯错，所以以此记录，来防止以后又犯此类错误
*/
/*
@203：给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
本题思路没啥难度，但是由于报错和没有处理头节点，我还是会写错
思路：遍历链表即可
*/
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
        return head;
        ListNode* dommy=new ListNode();//创建虚拟节点
        dommy->next=head;
        ListNode* current=dommy;
        while(current->next)//只判断当前节点的下一个节点是否为空即可
        {
            if (current->next->val==val)
            {
                ListNode* temp=current->next;
                current->next=current->next->next;//安全跳过被删节点
                delete temp;
            }
            else{
                current=current->next;
            }
        }
        ListNode* newhead=dommy->next;//拿到新的头节点
        delete dommy;//删除虚拟头节点
        return newhead;
    }
};
/*
@83:给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
本题删除重复元素也不是很难，主要还是空指针访问的问题
思路同上，遍历链表

注意：本题不需要使用虚拟头节点，因为题目说明是每个元素出现一次，而不是全部删除，所以我们可以由此得出使用虚拟头节点的条件就是当我们需要
完全遍历整个链表时，我们就需要遍历整个链表，
1.就是要对头节点做出改变的时候
2.需要合并两个链表的时候
3.反转或者分割链表
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        return head;
        // ListNode* dommy=new ListNode();
        // dommy->next=head;
        ListNode* current=head;
        while(current->next)
        {
            if(current->val==current->next->val)
            {
                ListNode* tem=current->next;
                current->next=current->next->next;
                delete tem;
            }
            else{
                current=current->next;
            }
        }
        // ListNode* newhead=dommy->next;
        // delete dommy;
        return head;
    }
};