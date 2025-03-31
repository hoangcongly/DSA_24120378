#include <iostream>
using namespace std;

// struct Node
// {
//     int data;
//     Node*next;
// };
// struct ListNode
// {
//     Node*head;
//     Node*tail;
// };
// Node*CreateNode(int value)
// {
//     Node*newNode= new Node();
//     newNode->data=value;
//     newNode->next=NULL;
//     return newNode;
// }
struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev; // Con trỏ trỏ đến node trước đó

    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

ListNode* insertionSortList(ListNode* head) 
{
    ListNode*curi= head->next;
    while(curi!=NULL)
    {
        int key= curi->val;
        ListNode*curj= curi->prev;
        while(curj->val>key)
        {
            curj->next->val=curi->val;
            curj=curj->prev;
        }
        if(curj) curj->prev->val=key;
        else head->val=key;
        curi=curi->next;
    }
    return head;
}