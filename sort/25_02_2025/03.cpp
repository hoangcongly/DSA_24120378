#include <iostream>
#include <queue>
using namespace std;

bool is_PrimeNumber(int n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
int main()
{
    queue<int> q;
    int n;
    cin >> n;
    for(int i=2; i<=n, i<10; i++)
    {
        if(is_PrimeNumber(i))
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        for(int i=1; i<=9; i++)
        {
            int k=q.front()*10+i;
            if(k<=n&& is_PrimeNumber(k))
            {
                q.push(q.front()*10+i);
            }
        }
        cout << q.front()<< " ";
        q.pop();
    }
    return 0;
}