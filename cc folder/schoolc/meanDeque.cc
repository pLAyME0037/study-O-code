#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {10, 20, 30};
    dq.push_front(5);
    dq.push_back(40);
    cout << "first number " << dq.front() << " last number " << dq.back() << endl;
    cout << "dq: \n";
    for (const auto eledq : dq)
    {
        cout << eledq <<"\n";
    }
    return 0;
}
