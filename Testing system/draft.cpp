// Khoruzhii Kirill, DGAP
// 

#include <iostream>          
#include <cmath>  
#include <string>     
#include <set> 

// class X
// {
//     int *a;
// public:
//     // конструктор копирования
//     X(const X& rhs)
//     {
//         a = new int;
//         *a = *rhs.a;
//     }
//     // конструктор копирования
//     X(X&& rhs)
//     {
//         int *tmp;
//         a = new int;
//         tmp = a;
//         a = rhs.a;
//         rhs.a = tmp;
//     }
// };
 
int main()                         
{   
    using namespace std;
    set<int> s {1, 2, 3, 4, 5, 6};
    s.erase(2);

    set<int>::iterator it;

    it = s.find(6);

    cout << *it;

    return 0;                       
}