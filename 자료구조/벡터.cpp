#include <iostream>
#include <vector> // Header 에 벡터 선언

using namespace std;

// 배열은 capacity가 정적임, 따라서 초기화한 capacity 이상의 값을 넣는게 불가능
// 선언법: vector<자료형> 변수이름(capacity);
// vector는 capacity가 가변적임

// vector<int> v; capacity가 얼마나 들어갈지 모를 때
// vector<int> v(5); // 5의 capacity를 가지는 벡터에서 안의 원소는 0으로 초기화
// vector<int> v(5, 2); // 5의 capacity를 가지는 벡터에서 안의 원소는 모두 2로 초기화


vector<int> v; // 벡터 초기화

int main() {
    v.push_back(5); // 맨 뒤에 원소를 하나 추가
    v.push_back(3);
    v.push_back(1);

    v.pop_back(); // 맨 뒤에 원소를 하나 제거 (capacity 도 지움)

    cout << v.front(); // 첫번째 원소를 참조한다
    cout << endl;
    cout << v.back(); // 마지막 원소를 참조한다
}
