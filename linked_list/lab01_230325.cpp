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
        if(coef==0) return;
        Node*newNode=CreateNode(coef, exp);
        if(dt->head==NULL|| dt->head->exp<exp)
        {
            newNode->pNext=dt->head;
            dt->head=newNode;
            if(dt->tail==NULL) dt->tail=newNode;
            return;
        }
        Node*cur=dt->head;
        Node*prev=NULL;
        while(cur!=NULL&& cur->exp>exp)
        {
            prev=cur;
            cur=cur->pNext;
        }
        if (cur && cur->exp == exp) {  
            // Nếu đã có một hạng tử có cùng số mũ, cộng hệ số lại
            cur->coef += coef;
            if (cur->coef == 0) { // Nếu hệ số trở thành 0, loại bỏ node
                if (prev) prev->pNext = cur->pNext;
                else dt->head = cur->pNext;
                delete cur;
            }
        } else {
            // Chèn vào vị trí tìm được (trước `cur`)
            newNode->pNext = cur;
            if (prev) prev->pNext = newNode;
            else dt->head = newNode;
        }
    }



