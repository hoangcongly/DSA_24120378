#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*pNext;
};
struct DanhSach
{
    Node*pHead;
    Node*pTail;
};
Node*Create_List(int*a, int n)
{
    Node*head=NULL;
    Node*tail=NULL;
    for(int i=0; i<n; i++)
    {
        Node*newNode= new Node();
        newNode->data=a[i];
        newNode->pNext=NULL;
        if(head==NULL) 
        {
            head=tail=newNode;
        }
        else
        {
            tail->pNext=newNode;
            tail=newNode;
        }
    }
    return head;
}
void printList(Node*head)
{
    Node*temp=head;
    while(temp!=NULL) 
    {
        cout<< temp->data << "->" ;
        temp=temp->pNext;
    }
}
int dem_so_luong_phan_tu(Node*head)
{
    int count=0;
    Node*temp= head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->pNext;
    }
    return count;
}
bool insert_Node(Node*&head, int data, int pos)
{
    Node*newNode=new Node();
    newNode->data=data;
    newNode->pNext= NULL;
    if(pos=0)
    {
        newNode->pNext= head;
        head=newNode;
        return true;
    }
    Node*temp= head;
    int count=0;
    while(temp!=NULL && count < pos-1)
    {
        temp=temp->pNext;
        count++;
    }
    if(temp==NULL) return false;
    newNode->pNext= temp->pNext;
    temp->pNext=newNode;
    return true;
}
int search_value(Node*head, int value)
{
    Node*temp=head;
    int pos=0;
    while(temp!=NULL)
    {
        if(temp->data==value) return pos;
        pos++;
        temp=temp->pNext;
    }
    return -1;
}
bool deleteNode_pos(Node*&head, int pos)
{
    Node*temp=head;
    int count=0;
    if(pos==0)
    {
        Node*tmp= head;
        head=head->pNext;
        delete tmp;
        return true;
    }
    while(temp!=NULL&& count<pos-1)
    {
        // 1->2->5->3->4 pos=3, count =2, llpos2
        count++;
        temp=temp->pNext;
    }
    if(temp==NULL&&temp->pNext==NULL) return false;
    Node *tmp= temp->pNext;
    temp->pNext=tmp->pNext;
    delete tmp;
    return true;
}
bool delete_Value(Node*&head, int value)
{
    if(head==NULL) return false;
    if(head->data==value)
    {
        Node*tmp= head;
        head=head->pNext;
        delete tmp;
        return true;
    }
    Node*temp=head;
   while(temp!=NULL&& temp->pNext->data!=value)
   {
        temp=temp->pNext;
   }
   if(temp->pNext==NULL) return false;
   Node *tmp= temp->pNext;
   temp->pNext=tmp->pNext;
   delete tmp;
   return true;
}
bool update_ValueNode(Node*head,int pos, int value)
{
    if(head==NULL) return false;
    if(pos==0)
    {
        head->data=value;
        return true;
    }
    Node*cur= head;
    int count=0;
    while(cur!=NULL&&count<pos-1)
    {
        // 1 3 4 7 2 pos=3, pos
        cur=cur->pNext;
        count++;
    }
    if(cur==NULL||cur->pNext==NULL) return false;
    cur->pNext->data=value;
    return true;
}
Node* reverseLinkedList(Node*head)
{
    Node*prev=NULL;
    Node*cur=head;
    Node*next=NULL;
    while(cur!=NULL)
    {
        next= cur->pNext;
        cur->pNext= prev;
        prev= cur;
        cur=next;
    }
    return prev;
}
// void sort_LinkedList_Bubble(Node*head)
// {
//     if(head==NULL) return;
//     Node*cur=head;
//     while(cur->pNext->pNext!=NULL)
//     {
//         while(cur->pNext!=NULL)
//         {
//             if(cur->data>cur->pNext->data)
//             {
//                 int temp= cur->data;
//                 cur->data=cur->pNext->data;
//                 cur->pNext->data=temp;
//             }
//         }
//         cur=cur->pNext;
//     }dir
// }
Node*merge(Node*left, Node*right)
{
    if(!left) return right;
    if(!right) return left;
    if(left->data<right->data)
    {
        left->pNext=merge(left->pNext, right);
        return left;
    }
    else 
    {
        right->pNext=merge(left,right->pNext);
        return right;
    }
}
Node* mergeSort(Node*head)
{
    if(head==NULL|| head->pNext==NULL) return head;
    Node*slow=head;
    Node*fast= head->pNext;
    while(fast&&fast->pNext)
    {
        slow=slow->pNext;
        fast=fast->pNext->pNext;
    }
    Node*mid=slow->pNext;
    slow->pNext=NULL;
    return merge(mergeSort(head),mergeSort(mid));
}
void remove_Duplicate(Node*head)
{
    if(head==NULL) return;
    Node*cur=head;
    while(cur->pNext!=NULL)
    {
        if(cur->data== cur->pNext->data)
        {
            Node*temp= cur->pNext;
            cur->pNext=temp->pNext;
            delete temp;
        }
        else
        {
            cur=cur->pNext;
        }
    }
}
void 