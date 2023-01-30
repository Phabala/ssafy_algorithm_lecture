# Parsing 이란?
- 문자열 구조 파악을 뜻한다.
- 이곳에서 파싱은 문자열의 구조를 파악하여, 필요한 정보만 가져오는 것을 뜻한다.

# Parsing에 가장 많이 쓰이는 메서드 세가지
## `find()`
**특정 문자열이 어디에 있는지 검색하여, index를 알려준다.**
문자 or 문자열을 찾을 때 사용하는 메소드
- 찾으면 index 값이 리턴된다.
- 못 찾으면 (unsigned int) -1이 리턴된다.
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1 = "Z_KFC_ZZZ";
    cout << str1.find("KFC") << "\n"; // 답: 2
    cout << (int)str1.find("BBQ") << "\n"; // 답: -1 (왜 앞에 (int)를 해준걸까?)

    return 0;
}
```

**추가 옵션**
- 몇 번 index부터 검색을 시작할지 명시할 수 있음
- 파싱에 많이 사용되는 기능이기에 꼭 알아 둘 것.
> 4번 index부터 검색을 시작한다.
```cpp
string str1 = "Z_KFC_ZZZ_KFC_";
cout << str1.find("KFC") << "\n"; // 답: 2
cout << str1.find("KFC", 4) << "\n"; // 답: 10
```
## `substr()`
- 특정 index부터 몇 글자수 문자열을 추출한다.
> **2번 index** 부터 **세 글자**를 추출하는 소스코드
```cpp
string str1 = "Z_KFC_ZZZ_KFC_";
string ret = str1.substr(2, 3); // 유의사항: (소괄호) 안에 글자 수를 기입해야 한다.
cout << ret; // 답: KFC (2번 인덱스 부터 세 글자 출력)
```
## `stoi()`
- 문자열을 수로 변환하는 메소드 ***(string to int)***
- 수 형태로 되어있는 문자열(string)을 수(int)로 변경하는 함수
> int 말고 다른 형으로 바꾸는 메소드도 있지만, 우선 여기서 다루지 않는다.
```cpp
string str = "1432";
int ret = stoi(str); // ret == 1432 (int 형)
cout << ret + 100; // 답: 1532
```

# `find()` 응용 : 단어 개수 찾기
## 기본 : for 문을 쓰지 않고 구현하기
한 문자열에 "ABC"가 2개 존재한다.
두 ABC 문자열의 index를 찾아라.
> a는 str를 0부터 찾기 시작, b는 str를 3부터 찾기 시작
```cpp
string str = "__ABC__ABC___";

int a = str.find("ABC", 0); // 답: 2
int b = str.find("ABC", a + 1); // 답: 7

cout << a << b;
```
## 응용 : for 문 써서 구현하기
한 문자열에 "ABC"가 2개 존재한다. 두 ABC 문자열의 index를 찾아라. (위 문제와 같다.)
> 첫 iteration의 **a** : 0 부터 찾기 시작, 답 2 <br>
> 두번째 iteration의 **a** : 3부터 찾기 시작, 답 7
```cpp
string str = "__ABC__ABC___";

int a = -1; // 모든 for 문 마다 1을 더해줘야 하므로 첫 iteration 에서 0으로 시작하기 위해 -1로 초기화
for (int i = 0; i < 2; i++) {
    a = str.find("ABC", a + 1);
    cout << a;
}
```
## 단어 개수 구하기
긴 문자열에서 ABC가 총 몇개 존재할까?
> 위의 for 문과 다르게 몇개의 문자열이 존재하는지 모를 때 작성하는 코드. `while(1)` 로 무한 루프를 돌리고 `str.find("ABC", a + 1);` 이 더이상 `ABC`를 찾지 못해 `-1`을 반환할 때 while 문을 탈출한다. (a값을 계속 다른 변수에 저장하면 몇 번째 index 들에 있는지도 알 수 있다.)
```cpp
string str = "__ABC__ABC___";

int a = -1;
int cnt = 0;
while(1) {
    a = str.find("ABC", a + 1);
    if (a == -1) break; // a+1 인덱스 이후 "ABC"가 존재 하지 않을 경우 while 문 탈출
    cnt++;
}

cout << cnt;
```