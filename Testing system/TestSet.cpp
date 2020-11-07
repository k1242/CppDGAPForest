// erasing from set
#include <iostream>
#include <set>

int main ()
{
  using namespace std;
  set<int> test_set;
  set<int>::iterator it;

  // insert some values:
  for (int i=1; i<10; i++) test_set.insert(i*10);  // 10 20 30 40 50 60 70 80 90

  it = test_set.begin();
  ++it;                                         // "it" points now to 20

  test_set.erase (it);

  test_set.erase (40);

  it = test_set.find (70);
  test_set.erase (it, test_set.end());

  cout << "test set contains:\n\t";
  for (it=test_set.begin(); it!=test_set.end(); ++it)
      cout << *it << " ";
  cout << '\n';

  return 0;
}