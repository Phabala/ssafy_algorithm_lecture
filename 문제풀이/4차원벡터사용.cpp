#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string input[2];
// 3차원 벡터
// 3차원: 길이(n), 2차원: input1~2(인덱스 두개), 1차원: n의 길이만큼 잘라놓은 string들이 실제 담겨 있는 곳, 0차원: string 의 char 1개
vector<vector<vector<string>>> storage;

int main()
{
    // 입력 받기
    cin >> input[0] >> input[1];

    // 3중첩 for문: 인풋 두개를 길이별로 다 분해해서 3차원 벡터에 나눠놓기
    for (int n = 1; n <= input[1].length(); n++)
    {
        vector<vector<string>> tmp; // n == 1~ length() 를 추가
        for (int y = 0; y < 2; y++)
        {
            vector<string> v; // input[0] ~input[1] 추가
            for (int i = 0; i < input[y].length() + 1 - n; i++)
            {
                v.push_back(input[y].substr(i, n)); // 인덱스 i부터 n만큼 자른 string(1차원) 들을 2차원인 v에 push_back
            }
            tmp.push_back(v); // string 들이 인풋 개수인 2종류로 나뉘어 담겨있는 2차원인 v를 3차원인 tmp에 push_back
        }
        storage.push_back(tmp); // 길이를 n만큼 잘라놓은 것들을 input 종류(2가지)에 따라 묶어놓은 3차원인 tmp를 4차원인 storage에 push_back
    }

    string longest = "";
    for (int i = 0; i < storage.size(); i++)
    {
        for (int j = 0; j < storage[i][0].size(); j++)
        {
            for (int k = 0; k < storage[i][1].size(); k++)
            {
                // 인풋 별로 나눠놓은 길이가 같은 substr 들을 모두 매칭시켜, 그 둘이 같은 단어이고
                // 지금까지 발견된 단어들중에 제일 길이가 길다면 longest 변수에 저장
                if (storage[i][0][j] == storage[i][1][k] && longest.size() < storage[i][0][0].size())
                    longest = storage[i][0][j];
            }
        }
    }

    // 제일 긴 단어 출력
    cout << longest;
}

// 개발 전 설계
// input1과 input2 를 n (n의 크기는 1~ input2의 길이) 만큼 잘라놓은 것들을 모아놓은 다음에,
// 전부 비교해봐서 같은게 있으면 return 하기
// 차원 설계: 0차원 - 길이 n, 1차원 - input1과 input2, 2차원 - string 실제 값 <-- 부정확한 표현