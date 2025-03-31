/*
Giả sử chúng ta có một đa thức có dạng sau:
P(x) = anx
n + an−1x
n−1 + · · · + a1x + a0

Trong đó, mỗi hệ số ai (với i = 0, 1, . . . , n) là một giá trị số thực, và các mũ i là các số nguyên không
âm.
Ta sẽ biểu diễn đa thức này dưới dạng một danh sách liên kết đơn, trong đó mỗi nút của danh sách
chứa:
Hệ số của một hạng tử của đa thức.
Mũ của hạng tử đó.
Con trỏ tới nút kế tiếp trong danh sách.
Viết chương trình để cộng hoặc nhân hai đa thức đã được biểu diễn dưới dạng danh sách liên kết đơn.
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    double coef;
    int exp;
    Node*pNext;
};
struct DaThuc
{
    Node*head;
    Node*tail;
};
DaThuc *CreateDaThuc()
{
    DaThuc*dt=new DaThuc();
    dt->head=dt->tail=NULL;
    return dt;
}
Node*CreateNode(double coef, int exp)
{
    Node*newNode= new Node();
    newNode->coef=coef;
    newNode->exp=exp;
    newNode->pNext=NULL;
    return newNode;
}

void insertTerm(DaThuc*dt, double coef, int exp)
{
    if(coef=0) return;
    Node*newNode= CreateNode(coef, exp);
    if(dt->head==NULL|| dt->head->exp<exp)
    {
        newNode->pNext=dt->head;
        dt->head=newNode;
        if(dt->tail==NULL) dt->head=dt->tail=newNode;
        return;
    }
    Node*cur=dt->head;
    Node*prev=NULL;
    while(cur!=NULL&& cur->exp>exp)
    {
        prev=cur;
        cur=cur->pNext;
    }
    if(cur!=NULL&& cur->exp== exp)
    {
        cur->coef+=coef;
        if(cur->coef==0) 
        {
            if(prev!=NULL) prev->pNext=cur->pNext;
            else dt->head=dt->head->pNext;
        }
    }
    else
    {
        newNode->pNext=cur;
        if(prev!=NULL) prev->pNext=newNode;
        else dt->head= newNode;
    }
}
DaThuc*multiplyDaThuc(DaThuc*dt1, DaThuc*dt2)
{
    DaThuc*newdt= CreateDaThuc();
    for(Node*term1=dt1->head; term1!=NULL; term1=term1->pNext)
    {
        for(Node*term2=dt2->head;term2!=NULL; term2=term2->pNext)
        {
            double coef= term1->coef*term2->coef;
            int exp= term1->exp+term2->exp;
            insertTerm(newdt,coef,exp);
        }
    }
    return newdt;
}



