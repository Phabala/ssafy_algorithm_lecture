# Hash
C에서는 현업에서 직접 구현해서 쓰고, C++은 보통 라이브러리를 쓴다.

각 언어마다 Hash Table 자료구조 구현체가 이름이 다르다.
현재 기준 보편적인 이름은 Dictionary
C#, Python : Dictionary
Java : HashMap
C++ : map(Binary Search Tree 자료구조), unordered_map <-- 둘중 편한거 쓰면 된다.
추천하는건 unordered_map, 안정적인 속도가 더 잘나옴.

배열의 한계
1. index에 음수 사용 불가
2. index에 아~~~주 큰 수 사용 불가
3. index에 문자열 사용 불가

DAT의 단점을 극복한게 Hash

```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map> // uno 하고 탭 하면 자동완성됨
#include <string>
using namespace std;

map<int, string> kkk;
unordered_map<int, string> ggg;

string ccc[100];

int main() {
    ccc[100] = "KDKS";

    kkk[100] = "HUHUHU";
    ggg[100] = "HAHAHA";
    cout << ggg[100] << '\n';
    cout << kkk[100] << '\n';
}
```

배열 속 문자열 갯수 출력
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map> // uno 하고 탭 하면 자동완성됨
#include <string>
using namespace std;

string arr[] = { "HI", "HI", "GGG", "HI", "GGG" };

unordered_map<string, int> um; // key = 문자, value = 빈도수

int main() {

    // 입력 받기 전 사전 세팅 (빠른 검색을 위한 초기화)
    for (int i = 0; i < 5; i++) {
        um[arr[i]] += 1;
    }

    string str;
    cin >> str;

    // 검색시작
    cout << um[str];
}
```

C++ 용 Unordered Map 유의사항:
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map> // uno 하고 탭 하면 자동완성됨
#include <string>
using namespace std;

string arr[] = { "HI", "HI", "GGG", "HI", "GGG" };

unordered_map<string, int> um; // key = 문자, value = 빈도수

int main() {

    // 입력 받기 전 사전 세팅 (빠른 검색을 위한 초기화)
    for (int i = 0; i < 5; i++) {
        um[arr[i]] += 1;
    }

    string str = "BBQ";

    if (um.count(str) == 0) { // 이렇게 해야됨.
        cout << "없네~";
    }

    if (um[str] == 0) {
        cout << "없넹"; // 이렇게 짜면 안된다. 물어보기만 해도 해쉬 테이블에 { "BBQ" : 0 }이 추가되버린다.
    } 

    if (um.count(str) == 0) { // 위의 um[str] == 0 때문에 출력이 안된다.
        cout << "출력이 안되는 문구";
    }
}
```

나의 num, name 중 하나 물어보기 풀이
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map> // uno 하고 탭 하면 자동완성됨
#include <string>
using namespace std;

// 해쉬 하나 쓰는 방법도 있고, 두개 쓰는 방법도 있다.
unordered_map<int, string> um1;
unordered_map<string, int> um2;

int main() {
	for (int i = 0; i < 4; i++) {
		int num;
		string name;
		cin >> num >> name;
		um1.insert({ num, name });
		um2.insert({ name, num });
	}

	string input;
	cin >> input;
	if (input[0] >= '0' && input[0] <= '9') {
		if (um1.count(stoi(input) != 0)) {
			cout << um1[stoi(input)];
		}
		else {
			cout << "없다.";
		}
	}
	else {
		if (um2.count(input) != 0) {
			cout << um2[input];
		}
		else {
			cout << "없다.";
		}
	}
}
```

강사님의 num, name 풀이
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> d1, d2;

int main()
{    
    d1["jodan"] = 63;
    d2["63"] = "jodan";

    d1["park"] = "11";
    d2["11"] = "park";

    string str;
    cin >> str;

    if (d1.count(str) > 0) cout << d1[str];
    if (d2.count(str) > 0) cout << d2[str];


    return 0;
}
```

배열이 아니라 해쉬테이블에 저장하면 자료를 찾는데 O(N)이 아니라 O(1)이 나온다.
데이터베이스는 Hash 의 세상이다.

구조체 활용 문제 내 코드
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map> // uno 하고 탭 하면 자동완성됨
#include <string>
using namespace std;

struct Person {
	int age;
	string name;
	int IQ;
};

unordered_map<string, Person> um;

int main() {
	// struct를 key로...?

	Person tmp1 = { 15, "so", 56 };
	Person tmp2 = { 66, "go", 60 };
	Person tmp3 = { 15, "gi", 150 };

	um.insert({tmp1.name, tmp1 });
	um.insert({tmp2.name, tmp2 });
	um.insert({tmp3.name, tmp3 });
	int de = -1;

	string str; cin >> str;
	cout << um["so"].IQ;
}
```

구조체 활용 강사님 코드
> IQ도 Key로, Name도 Key로 넣어줬다.
> 이렇게 풀어도 시간복잡도는 걱정 안해도 된다. 주렁주렁 안 달려 있다.
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    int age;
    string name;
    string iq;
};

unordered_map<string, Node> um;

int main()
{    
    um["56"] = { 15, "SO", "56" };
    um["SO"] = { 15, "SO", "56" };

    um["60"] = { 66, "GO", "60" };
    um["GO"] = { 66, "GO", "60" };

    string str;
    cin >> str;

    if (um.count(str)) {
        cout << um[str].name << '\n';
        cout << um[str].age << '\n';
        cout << um[str].iq << '\n';
    }

        return 0;
}
```

**Unordered Multi Map (유사)**
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, vector<int>> um; // 이렇게 하면 unordered multimap 안 써도 된다, 동일한 기능.

int main() {
	um["ABC"].push_back(10);
	um["ABC"].push_back(20);
	um["ABC"].push_back(50);
}
```

**숫자의 좌표 출력**
나의 풀이
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<int, vector<vector<int>>> um;

int main() {
	um[15] = { {0, 0} };
	um[11] = { 0, 1 };
	um[-7] = { 0, 2 };

	um[55] = { 1, 0 };
	um[-7] = { 1, 1 };
	um[11] = { 1, 2 };

	um[-7] = { 2, 0 };
	um[-55] = { 2, 1 };
	um[-9] = { 2, 2 };

	int de = -1;
}
```

강사님 풀이
```cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
struct Node {
    int y, x;
};

unordered_map<int, vector<Node>> um;

int main()
{
    int arr[3][3] = {
        15, 11, -7,
        55, -7, 11,
        -7, -55, -9
    };

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            um[arr[y][x]].push_back({ y, x });
        }
    }

    int tar = -7;
    int n = um[tar].size();
    for (int i = 0; i < n; i++) {
        //cout << um[tar][i].y << " , " << um[tar][i].x;
        Node ret = um[tar][i];
        cout << ret.y << "," << ret.x << "\n";
    }
    
    return 0;
}
```