#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
    char str[100] = "string";
    string s = "string";

    // 정석적인 길이 찾기 구현
    int len;

    for (int i = 0; i < 100; i++)
    {
        if (str[i] == '\0')
        {
            len = i;
            break;
        }
    }

    cout << len << endl;

    // cstring library
    cout << strlen(str);

    // string class (자료형)
    // string.length() : 길이
    cout << s.length();

    // quiz: 두개의 문자열이 동일하면 1, 아니면 0을 출력하는 프로그램
    char a[100] = "abc";
    char b[100] = "bcd";

    int isSame = 1;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] != b[i])
        {
            isSame = 0;
            break;
        }
    }

    cout << endl
         << isSame << endl;

    // cstring => strcmp
    // strcmp 값이 -1 이면, a가 b보다 앞에 온다
    // 1이면, a가 b보다 뒤에 온다

    if (strcmp(a, b) != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }

    // string class
    string c = "abc";
    string d = "bcd";

    if (c < d)
    {                      // 사전순으로 비교한다는건 아스키 코드 값으로 비교한다는 것
        cout << 1 << endl; // 1이 나온다, 아스키 코드값이 a보다 b가 크기 때문
    }
    else
    {
        cout << 0 << endl;
    }

    // quiz: 두개의 문자열을 결합, c에 결합
    char e[100] = "str";
    char f[100] = "ing";

    int len_e = strlen(e);
    int len_f = strlen(f);

    for (int i = 0; i < len_e + len_f; i++)
    {
        e[i + len_e] = f[i];
    }
    e[len_e + len_f] = '\0'; // Visual Studio가 아닌 경우 \0 값이 다르게 나올 수 있으니 주의

    cout << e << endl;

    // cstring
    // strcat -> string concatenate
    // strcat(a, b) -> b가 a에 결합
    strcat(e, f);
    cout << e << endl;

    // string class
    // 연산자 사용 가능 -> += 결합
    string val1 = "str";
    string val2 = "ing";

    val1 += val2; // cf. 문자열은 사칙연산 중 + 만 됨.

    cout << val1 << endl;

    // 1. 문자열 복사하기
    // 2. 문자열 부분 찾아오기
    // 3. 문자열 특정 위치 찾기
    // 4. 문자열의 형태 변경
}
