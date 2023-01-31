#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string vect[100];
    int t = 0;

    cin >> str;

    string temp;
    int a = 0;
    int b;
    while (1)
    {
        b = str.find('_', a);
        if (b == -1)
        {
            b = str.length();
            temp = str.substr(a, b - a);
            if (temp != "")
                vect[t++] = temp;
            break;
        }

        temp = str.substr(a, b - a);
        if (temp != "")
            vect[t++] = temp;
        a = b + 1;
    }

    for (int i = 0; i < t; i++)
    {
        cout << i + 1 << "#" << vect[i] << endl;
    }
    return 0;
}