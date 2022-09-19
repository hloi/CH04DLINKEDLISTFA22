#include <iostream>
#include "list.h"

using namespace std;

using KW::list;

// declare the const list and use it with the const_iterator
template <typename T>
void print_list(const list<T>& a_list) {
    typename list<T>::const_iterator iter = a_list.begin();
    while (iter != a_list.end()) {
        cout << *iter;
        if (++iter != a_list.end())
            cout << ", ";
    }
    cout << endl;
}

int main() {
    list<int> a_list;
    a_list.push_front(2);
    a_list.push_back(5);
    a_list.push_back(8);

    print_list(a_list);


//    a_list.printInfo();
//    a_list.pop_back();
//    cout << "------------" << endl;
//    a_list.printInfo();
//    a_list.pop_front();
//    cout << "------------" << endl;
//    a_list.printInfo();



    return 0;
}
