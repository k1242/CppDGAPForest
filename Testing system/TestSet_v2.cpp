#include <iostream>
#include <chrono>

#include "../AVL_tree/AVL.cpp"
#include "../Red-black_tree/RB_Tree.cpp"



int main ()
{
    using namespace std;
    RBTree<int> test_struct = {};

    long double tmp_1 = 0;
    int rep_1 = 10 * 1000;
    int factor =  1;
    int rep_2 = 100;
    int N = 0; 

    int tmp_rand_num;

    auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<long double> elapsed = finish - start;


    // Будем измерять значения прия наличие [0, rep_2] * k элементов
    for (int _ = 0; _ < 1; ++_)
    {
        srand(_ * 42 + 42); 

        for (int k = 1; k <= 1000 * 100; k *= 10)
        {
            factor =  k;
            N = 0; 
            test_struct = {};
        
            // Получаем rep_2 точек в этом промежутке
            for (int j = 0; j < rep_2; ++j)
            {

                // Увеличиваем размеры структуры
                for (int i = (factor + rep_1) * j;
                     i < factor * (j+1) + rep_1 * j; 
                     ++i)
                {
                    test_struct.insert(rand()*rand());
                }

                // Далее rep_1 повторяем действие и измеряем время работы.
                start = std::chrono::high_resolution_clock::now();
                for (int i = factor * (j+1) + rep_1 * j; 
                    i < (factor + rep_1) * (j + 1); ++i)
                {
                    // Код для тестирования:

                    // -----------------------
                    // int rand_i = rand()*rand();
                    tmp_rand_num = rand()*rand();
                    test_struct.insert(tmp_rand_num);
                    // test_struct.find(rand()*rand());
                    test_struct.remove(tmp_rand_num);
                    // -----------------------
                }
                finish = std::chrono::high_resolution_clock::now();

                // for (int i = factor * (j+1) + rep_1 * j; 
                    // i < (factor + rep_1) * (j + 1); ++i)
                // {
                //     // Код для восстановления:

                //     // -----------------------
                //     // int rand_i = rand()*rand();
                //     test_struct.insert(rand()*rand());
                //     // test_struct.find(rand()*rand());
                    // test_struct.remove(rand()*rand());
                //     // -----------------------
                // }

                elapsed = (finish-start);
                tmp_1 = elapsed.count();
                N += factor;

                // вывод в формате .csv
                std::cout << N <<"," << tmp_1 << "\n";  

            }
        }
    }

}





