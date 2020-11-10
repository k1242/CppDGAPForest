#include <iostream>
#include <chrono>

#include "../AVL_tree/AVL.cpp"
#include "../Red-black_tree/RB_Tree.cpp"



int main ()
{
    using namespace std;
    AVL<int> test_struct = {};

    double tmp_1 = 0;
    int rep_1 = 1 * 1000 * 1000;
    int factor =  1;
    int rep_2 = 100;
    int N = 0; 

    auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;


    // Будем измерять значения прия наличие [0, rep_2] * k элементов
    for (int k = 1; k <= 1000 * 1000; k *= 10)
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
                test_struct.insert(i);
            }

            // Далее rep_1 повторяем действие и измеряем время работы.
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

            // вывод в формате .csv
            std::cout << N <<"," << tmp_1 << "\n";  

        }
    }

}





