#include <iostream>
#include <chrono>
// #include <set>
#include "AVL.cpp"
#include "RB_Tree.cpp"



int main ()
{
    using namespace std;
    RBTree<int> test_struct = {};

    double tmp_1 = 0;
    int rep_1 = 1 * 1000 * 1000;
    int factor =  1;
    int N = 0; 

    auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;


    for (int k = 1; k <= 10 * 1000; k *= 10)
    {
        factor =  k;
        N = 0; 
        test_struct = {};
    
        for (int j = 0; j < 100; ++j)
        {

            for (int i = (factor + rep_1) * j;
                 i < factor * (j+1) + rep_1 * j; 
                 ++i)
            {
                test_struct.insert(i);
            }

            start = std::chrono::high_resolution_clock::now();
            for (int i = factor * (j+1) + rep_1 * j; 
                i < (factor + rep_1) * (j + 1); ++i)
            {
                // Код для тестирования:

                // -----------------------
                // test_struct.insert(i);
                // test_struct.find(100);
                test_struct.remove(i*2);
                // -----------------------
            }
            finish = std::chrono::high_resolution_clock::now();

            elapsed = finish-start;
            tmp_1 = elapsed.count();
            N += factor;

            std::cout << N <<"," << tmp_1 << "\n";  

        }
    }

}





