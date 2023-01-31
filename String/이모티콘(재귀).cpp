#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string input;
int bracketLeftCnt;
int bracketRightCnt;
int smileCnt;
int isMouth;

void bracketLeftCount(int index)
{
    if (input[index] == '(')
    {
        bracketLeftCnt++;
        bracketLeftCount(index + 1);
    }
}

void bracketLeftChange(int index)
{
    if (input[index] == '(')
    {
        bracketLeftCount(index);
        input.erase(index, bracketLeftCnt);
        input.insert(index, "(");
    }
    bracketLeftCnt = 0;
}

void bracketRightCount(int index)
{
    if (input[index] == ')')
    {
        bracketRightCnt++;
        bracketRightCount(index + 1);
    }
}

void bracketRightChange(int index)
{
    if (input[index] == ')')
    {
        bracketRightCount(index);
        input.erase(index, bracketRightCnt);
        input.insert(index, ")");
    }
    bracketRightCnt = 0;
}

void smileCount(int index)
{
    if (input[index] == '^')
    {
        smileCnt++;
        smileCount(index + 1);
    }
}

void smileChange(int index)
{
    if (input[index] == '^')
    {
        smileCount(index);
        if (smileCnt > 2)
        {
            input.erase(index, smileCnt);
            input.insert(index, "^^");
        }
    }
    smileCnt = 0;
}

void checkMouth(int index)
{
    if (input[index] == '^' && input[index + 2] == '^')
    {
        isMouth = 1;
    }
}

void mouthChange(int index)
{
    if (input[index] == '^')
    {
        checkMouth(index);
        if (isMouth == 1)
        {
            input[index + 1] = '_';
        }
    }
    isMouth = 0;
}

int main()
{
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '\0')
        {
            break;
        }
        bracketLeftChange(i);
        bracketRightChange(i);
        smileChange(i);
        mouthChange(i);
    }
    cout << input;
}

// 함수를 세 종류를 만들자
// 괄호가 2개 이상인 것을 두개로 만들기
// 눈 세개 이상인지 체크하여 두개로 바꾸기
// 눈과 눈 사이가 한 글자인 경우, '_'로 바꾸기