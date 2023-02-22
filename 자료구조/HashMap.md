# Hash Map
**Key 와 Value로 저장하는 자료구조**

DAT의 단점 보완.
Key는 문자열, 음수, 매우 큰 값 가능

**Hash Function** : 특정 값들을 찾아줄 수 있는 'KEY'로 변환하는 함수

해싱의 문제점 두가지
1. hash mak?? => 효율성 = hash Function (잘 못적음)
2. hash collision => 해결방안 1. Hash Chaining, 2. Open Addressing

Hash Function 은 만들 필요가 없으면 굳이 안만든다.
<img> 나중에 넣기

> Hash Map
> 
> C++ 에서 쓸 수 있는 map의 종류는 두개가 있다.
> 
> #1. unordered_map <- 얘를 써라. (정렬되지 않은 맵) hash-table 구조를 이용. 만들고, 삭제하고, 탐색한다. -> O(1) ~ O(logN)
> string의 데이터를 전부 변환.
> 
> #2. map <- (정렬된 맵) red-black tree 구조. 새로 만들고, 삭제하고, 탐색한다 -> O(logN)    
> 비교적으로 양이 많은 경우 불리하다. string을 key로 쓸 때는 간혹 유리하다.

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 200000000, 300000000, 4, 5};
    /*MAP 생성*/
    /*unordered_map<key type, value type>*/
    unordered_map<int, int>um;

    for (int i = 0; i < 5; i++) {
        um.insert({ arr[i], 1 }); // 1이 아니라 i를 사용하면 index처럼 사용 가능
    }
    cout << um[200000000]; // um에 20억이 있니? 
}
```

만약 이미 MAP에 키가 등록되어 있다면 해당 키 값에 연결된 value + 1
(`find` 의 값이 없으면 `um.end()`를 돌려준다.)
> 해시 맵의 key, value랑 JSON에서의 key, value랑 쓰는 양상이 다른가?
```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 200000000, 300000000, 4, 5};
    /*MAP 생성*/
    /*unordered_map<key type, value type>*/
    unordered_map<int, int>um;

    for (int i = 0; i < 5; i++) {
        if(um.find(arr[i]) != um.end()) { // arr[i]를 찾았다면
            um[arr[i]]++;
        }
        else { // 만약 key가 없다면, 새로 찾은 숫자 = value = 1
            um.insert({ arr[i], 1 }); /*insert(key, value)*/
        }
    }

    // 1. um[3]은 뭐가 출력될까?
    // 2. map에 존재할까?
    // um[key] -> key가 생성됩니다.
    cout << um[3]; // 출력 : 0. 키가 없는걸 찾으면 문제가 생길 수 있다. (새로운 키가 생김)
}
```

**traversal / iteration**
> 시간이 꽤 걸린다. (정확한 시간복잡도는 특정짓기 어려움)
> 앞에서부터 끝까지 값을 볼 수 있는 방법이지만, 많은 문제에서 시간초과가 나온다. 디버깅 정도로만 사용하자
```cpp
for(auto it = um.begin(); it != um.end(); it++) { // it 는 iteration의 약자
    cout << it->first << " " << it->second << '\n';
}
```