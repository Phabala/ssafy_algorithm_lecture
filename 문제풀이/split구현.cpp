#include <iostream>
#include <vector>

vector<string> split(string input, char delimeter)
{
    vector<string> tmp_vec;
    int st = 0;
    for (int i = 0; i <= input.length(); i++)
    {                      // 사이즈 길이에서도 돌려야함
        int size = i - st; // size는 현재 인덱스 - st
        if (input[i] == delimeter || i == input.length())
        { // 델리미터와 같거나 문자가 끝났을 때
            string tmp_str = input.substr(st, size);
            tmp_vec.push_back(tmp_str); // 문자열 substr을 puth_back
            st = i + 1;                 // 시작점을 delimeter 다음으로 놓음
        }
    }
    return tmp_vec;
}