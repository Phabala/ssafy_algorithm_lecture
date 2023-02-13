#include <iostream>
#include <algorithm>
#include <queue> // priority queue 포함
using namespace std;
struct Student
{
    string name; // 이름
    int age;     // 나이
    int grade;   // 점수
    bool operator<(Student right) const
    {
        if (grade > right.grade)
            return false; // 올바른 / 원하는 상황일떄 true
        if (grade < right.grade)
            return true;
        if (age > right.age)
            return false;
        if (age < right.age)
            return true;
        if (name < right.name)
            return false;
        if (name > right.name)
            return true;
        return false;
    }
};
struct ssafycmp
{
    bool operator()(Student left, Student right)
    {
        if (left.grade > right.grade)
            return false; // 올바른 / 원하는 상황일떄 true
        if (left.grade < right.grade)
            return true;
        if (left.age > right.age)
            return false;
        if (left.age < right.age)
            return true;
        if (left.name < right.name)
            return false;
        if (left.name > right.name)
            return true;
        return false;
    }
};
// sort
// sort(first, last, cmp) default cmp : <
// --> 작은거부터 앞으로 가는 오름차순 정렬
// left < right --> 작은거 우선으로 정렬
// pq
// priority_queue<ty, container, cmp> default cmp : <
// --> 큰거부터 나오는 MAX HEAP
// left < right --> 큰거부터 우선순위 가짐
struct cmp
{
    // PQ -> < 쓰면 : MAX HEAP
    // sort떄와 동일한 생각으로 기준을 잡는다?
    // 올바른 상황 (즉, 내가 원하는 상황일때) -> return false;
    bool operator()(int left, int right)
    {
        // return left > right;
        if (left > right) // 우리가 원하는 상태?
            return true;
        if (left < right)
            return false;
        return false;
    }
};
bool qcmp(int left, int right)
{
    // 짝수 우선
    if (left % 2 == 0 && right % 2 == 1)
        return true;
    if (left % 2 == 1 && right % 2 == 0)
        return false;
    // 짝수라면 내림차순
    if (left % 2 == 0 && right % 2 == 0 && left > right)
        return true;
    if (left % 2 == 0 && right % 2 == 0 && left < right)
        return false;
    // 홀수라면 오름차순
    if (left % 2 == 1 && right % 2 == 1 && left < right)
        return true;
    if (left % 2 == 1 && right % 2 == 1 && left > right)
        return false;
    return false;
}
int main()
{
    int arr[] = {1, 4, 5, 3, 2};
    // #1 defaut : MAX heap : (int에서) 가장 큰 값이 우선순위를 갖는다.
    // priority_queue<int>pq;
    // 삽입 : push()
    // 삭제 : pop()
    // 맨 위 (우선순위가 가장 높은 값) return : q.top()
    // 비어있는가? : empty()
    // for (int i = 0; i < 5; i++)
    //     pq.push(arr[i]); // heapify
    //  출력
    // while (!pq.empty()) {
    //     cout << pq.top() << " ";
    //     pq.pop(); // heapify
    // }
    //  #2. MIN Heap
    //  priority_queue<typename, container, less>
    //  typename : 자료형
    //  container : vector
    //  _Pr : less --> <
    //  less : Compare cmp X --> 함수 구조체
    //  함수로 넣어주면 안되고, 구조체 함수를 만들어서 넣어야 한다.
    // priority_queue<int, vector<int>, cmp>pq;
    // for (int i = 0; i < 5; i++)
    //     pq.push(arr[i]); // heapify
    //
    // while (!pq.empty()) {
    //     cout << pq.top() << " ";
    //     pq.pop(); // heapify
    // }
    //  #3. 사용자 정의 heap
    priority_queue<Student> pq;
    // #1. 점수 높은 순
    // #2. 나이 많은 순
    // #3. 이름 사전순
    pq.push({"송유빈", 3, 100});
    pq.push({"박준형", 4, 100});
    pq.push({"김택우", 2, 100});
    pq.push({"김기덕", 4, 100});
    pq.push({"이득화", 7, 25});
    while (!pq.empty())
    {
        Student now = pq.top();
        cout << now.name << " " << now.age << " " << now.grade << '\n';
        pq.pop();
    }
    // sort와 priority queue 언제 쓰는가?
    // sort : O(NlogN)
    // PQ : 삽입과 추출 O(logN)
    // 예시 - N개의 정수를 입력 받고 가장 큰 수를 출력하라
    // sort : 입력받고 -> 정렬 -> arr[N-1] == O(NlogN)
    // PQ : 입력받으면서 PQ 삽입(logN) -> heapify -> pq.top() // peek
    // 예시 2 - N개의 Query
    // 1 -> 삽입 (logN)
    // 2 -> 현재 가장 큰 값 삭제 (logN)
    // 0 -> 현재 가장 큰 값을 출력 (1)
    // sort : Q * O(NlogN)
    // PQ : Q * (logN)
    // sort : 딱 한번의 정렬로 해결이 가능할때
    // --> binary search, greedy
    // PQ : 계속해서 새로운 값이 삽입 / 추출 될떄 (변화가 있을때)
    cout << '\n';
    // QUIZ
    // 정렬 : 짝수 우선, 홀수 나중, 짝수는 내림차순, 홀수는 오름차순
    int brr[] = {1, 3, 4, 5, 2};
    // 4 2 1 3 5
    sort(brr, brr + 5, qcmp);
    for (int i = 0; i < 5; i++)
        cout << brr[i] << " ";
}