/*
Bài 1. Viết chương trình để thực hiện các thao tác với danh sách liên kết đơn bao gồm:
a. Tạo một danh sách liên kết đơn từ các giá trị nguyên.
b. In ra các phần tử trong danh sách.
c. Đếm số lượng phần tử trong danh sách liên kết.
d. Thêm node vào vị trí bất kỳ trong danh sách liên kết đơn.
e. Tìm kiếm một giá trị trong danh sách.
f. Xóa node tại vị trí bất kỳ trong danh sách liên kết đơn.
g. Xóa node chứa giá trị (được nhập từ bàn phím) trong danh sách liên kết đơn.
h. Cập nhật giá trị của node tại vị trí bất kỳ trong danh sách liên kết đơn.
i. Đảo ngược danh sách liên kết
j. Sắp xếp danh sách liên kết đơn
k. Loại bỏ các phần tử trùng trong danh sách liên kết đơn.
l. Xoay danh sách liên kết sang trái hoặc phải k lần.
m. Kiểm tra danh sách liên kết có phải là danh sách đối xứng không.
* Lưu ý:
 Các thao tác cần được xây dựng dưới dạng hàm.
 Sau khi chạy chương trình, người dùng sẽ thấy một menu với các lựa chọn tương ứng với từng thao
tác. Người dùng có thể chọn thao tác bằng cách nhập số tương ứng và chương trình sẽ thực hiện
thao tác đó.

Bài 2. Chia một danh sách liên kết thành hai danh sách mới, một danh sách chứa các node có giá trị lẻ, một
danh sách chứa các node có giá trị chẵn.

Bài 3. Cho hai danh sách liên kết đơn, mỗi danh sách chứa các phần tử là các số nguyên. Hãy thực hiện các
yêu cầu sau:
a. Nối hai danh sách liên kết đơn
b. Nối hai danh sách đơn sao cho các phần tử trong danh sách liên kết 1 xen kẽ với các phần tử trong
danh sách liên kết 2
c. Nối hai danh sách đơn sao cho danh sách liên kết cuối cùng có các phần tử lẻ nằm đầu danh sách
và phần tử chẵn nằm cuối danh sách.
d. Nối hai danh sách đơn sao cho các phần tử trong danh sách liên kết cuối cùng được sắp xếp theo
thứ tự tăng dần
*/
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
Node*rotateLeft(Node*head, int k)
{
    if(head==NULL|| head->pNext==NULL|| k==0) return head;
    Node*temp=head;
    int len=1;
    while(temp->pNext!=NULL)
    {
        temp=temp->pNext;
        len++;
    }
    k=k%len;
    if(k==0) return head;
    temp->pNext=head;
    Node*newTail=head;
    for(int i=0; i<k-1; i++) 
    {
        newTail=newTail->pNext;
    }
    head=newTail->pNext;
    newTail->pNext=NULL;
    return head;
}
bool isPalindrome(Node*head)
{
    if(head!=NULL|| head->pNext!=NULL) return true;
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL&& fast->pNext!=NULL) 
    {
        slow=slow->pNext;
        fast=fast->pNext->pNext;
    }
    Node*prev=NULL;
    while(slow!=NULL)
    {
        Node*next= slow->pNext;
        slow->pNext=prev;
        prev=slow;
        slow=next;
    }
    Node*secondHalf=prev;
    Node*firstHalf= head;
    while(secondHalf)
    {
        if(firstHalf->data!=secondHalf->data) return false;
        firstHalf=firstHalf->pNext;
        secondHalf=secondHalf->pNext;
    }
    return true;
}
Node*mergeList(Node*head1, Node*head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node*temp=head1;
    while(temp->pNext!=NULL) 
    {
        temp=temp->pNext;
    }
    temp->pNext= head2;
    return head1;
}
Node*mergeInterleaved(Node*head1, Node*head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node*p1=head1;
    Node*p2=head2;
    Node*next1,*next2;
    while(p1!=NULL&&p2!=NULL)
    {
        next1=p1->pNext;
        next2=p2->pNext;
        p1->pNext=p2;
        p1=next1;
        if(p1!=NULL)
        {
            p2->pNext=p1;
        }
        p2=next2;
    }
    return head1;
}
Node* mergeOddEven(Node*head1, Node*head2)
{
    Node*oddHead=NULL,*oddTail=NULL;
    Node*evenHead=NULL, *evenTail=NULL;
    Node*current= head1;
    while(current!=NULL)
    {
        Node*nextNode=current->pNext;
        if(current->data%2!=0)
        {
            if(oddHead==NULL) 
            {
                oddHead=oddTail=current;
            }
            else
            {
                oddTail->pNext=current;
                oddTail=current;
            }
        }
        else 
        {
            if(evenHead==NULL)
            {
                evenHead=evenTail=current;
            }
            else
            {
                evenTail->pNext=current;
                evenTail=current;
            }
        }
        current=nextNode;
    }
    current=head2;
    while(current!=NULL)
    {
        Node*nextNode=current->pNext;
        if(current->data%2!=0)
        {
            if(oddHead==NULL)
            {
                oddHead=oddTail=current;
            }
            else
            {
                oddTail->pNext=current;
                oddTail=current;
            }
        }
        else
        {
            if(evenHead==NULL)
            {
                evenHead=evenTail=current;
            }
            else
            {
                evenTail->pNext=current;
                evenTail=current;
            }
        }
        current=nextNode;
    }
    if(oddTail!=NULL) oddTail->pNext=evenHead;
    if(evenTail!=NULL) evenTail->pNext=NULL;
    return oddHead? oddHead:evenHead;
}
Node*mergeSortedList(Node*head1,Node*head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node*head=NULL;
    Node*tail=NULL;
    if(head1->data<head2->data) 
    {
        head=tail=head1;
        head1=head1->pNext;    
    }
    else
    {
        head=tail=head2;
        head2=head2->pNext;
    }
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            tail->pNext=head1;
            head1=head1->pNext;
        }
        else
        {
            tail->pNext=head2;
            head2=head2->pNext;
        }
        tail=tail->pNext;
    }
    if(head1!=NULL) tail->pNext=head1;
    else tail->pNext=head2; 
    return head;
}
// hàm chia danh sách thành 2 danh sách con, 1 danh sách lẻ và 1 danh sách chẵn
void splitList(Node*head,Node*&oddHead,Node*&evenHead)
{
    Node*oddTail=NULL;
    Node*evenTail=NULL;
    while(head!=NULL)
    {
        if(head->data%2!=0)
        {
            if(oddHead==NULL)
            {
                oddHead=oddTail=head;
            }
            else
            {
                oddTail->pNext=head;
                oddTail=oddTail->pNext;
            }
        }
        else
        {
            if(evenHead==NULL)
            {
                evenHead=evenTail=head;
            }
            else
            {
                evenTail->pNext=head;
                evenTail=evenTail->pNext;
            }
        }
        head=head->pNext;
    }
    if(oddTail!=NULL) oddTail->pNext=NULL;
    if(evenTail!=NULL) evenTail->pNext=NULL;
}

