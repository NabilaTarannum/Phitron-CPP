#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st = "aaaabbbaaazz";
    cout << st.find('b') << endl;
    cout << st.rfind('b') << endl;
    cout << st.find_first_of('b') << endl;
    cout << st.find_last_of('b') << endl;
    cout << st.find_first_not_of('b') << endl;
    cout << st.find_last_not_of('b') << endl;
    cout << st.substr(3, 5) << endl;
    return 0;
}