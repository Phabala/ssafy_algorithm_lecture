#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

// string methods
// 1. 길이 -> str.length()
// 2. 결합 -> str1 + str2
// 3. str은 대입이 가능하다 ( = )
// 4. 비교가 가능하다 ( == != < > )
// 5. 부분 문자열 구하기 str.substr("string", "st")
// 6. 문자열에 substring 존재 체크 (index) -> str.find()

int main()
{
    // quiz: 문자열 복사하기
    char a[100] = "string";
    char b[100];

    for (int i = 0; i < strlen(a); i++)
    {
        b[i] = a[i];
    }
    b[strlen(a)] = '\0'; // 이걸 안해주면 에러가 난다
    // 혹은

    // cstring
    // strcpy -> string copy
    // strcpy (복사하고자 하는 문자열의 위치, 복사하려고 하는 문자열)
    char c[100] = "string";
    char d[100];
    strcpy(d, c);

    cout << b << endl
         << d << endl;

    string e = "string";
    string f;
    f = e;
    cout << f << endl;

    // quiz: 부분 복사 (2개의 정수 입력 -> 2, 6
    char val1[100] = "string";
    char val2[100];
    int st, en;
    cin >> st >> en;

    for (int i = st; i < en; i++)
    {
        val2[i - st] = val1[i];
    }
    val2[en - st] = '\0';
    cout << val2 << endl;

    // cstring
    // 전체 복사 = strcpy
    // 일부분 복사 -> strncpy(복사해서 저장할 위치(주소), 복사할 위치, 복사 할 구간 크기)
    // 참고: string도 배열처럼 주소값을 저장
    st, en;
    cin >> st >> en;

    char abc[100] = "string";
    char abcd[100];
    strncpy(abcd, a + st, en - st);
    abcd[en - st] = '\0';
    cout << abcd << endl;

    // string
    // 문자열의 부문 문자열을 가져와라: substr() (섭 스트링)
    // substr(시작위치index, 구간 크기index)
    string newVal1 = "string";
    string newVal2;
    cin >> st >> en;

    // 만약 구간 크기가 문자열의 길이를 넘어간다면 -> 알아서 마지막까지로 잘라준다
    newVal2 = newVal1.substr(st, en - st);
    cout << newVal2 << endl;

    // quiz. 문자열에서 특정 substring이 등장하는 위치를 찾고 싶다.
    char quizA[100] = "string";
    char quizB[100] = "st";   // <- 0 출력
    char quizC[100] = "ring"; // <- 2 출력

    for (int i = 0; i < strlen(quizA) - strlen(quizB); i++)
    {
        int isSame = 0;
        for (int j = 0; j < strlen(quizB); j++)
        {
            if (quizA[i + j] == quizB[j])
            {
                isSame++;
            }
        }
        if (isSame == strlen(quizB))
        {
            cout << "문자열 존재 인덱스 : " << i << endl;
            break;
        }
    }

    // cstring
    // 비슷한게 있기는 하다, strstr(A, B) <- 많이 안씀
    cout << strstr(quizA, quizC) << endl;

    // string class
    // 부분 문자열을 찾으려고 한다 -> find()
    // str.find(내가 찾으려고 하는 substring) -> substring 을 찾은 첫 index를 return
    string aA = "stssst";
    string aB = "ww";

    if (aA.find(aB) == string::npos)
    { // 문자를 못찾았을 때 리턴하는 값 (-1로도 표현이 가능함)
        cout << 0 << endl;
    }
    else if (aA.find(aB) != -1)
    { // string::npos는 -1과 같음 (왜 그렇지?)
        cout << 1 << endl;
    }
}
