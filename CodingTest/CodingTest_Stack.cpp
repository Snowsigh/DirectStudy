#ifdef MyCoding
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int Finish = 0;
    int Update = 0;
    bool Fish = true;
    vector<int> FinishLine;
    vector<int> answer;

    for (int i = 0; i < progresses.size(); i++)
    {
        int Hun = progresses[i];
        while (Hun < 100)
        {
            Hun += speeds[i];
            Finish++; //완료까지 걸린 날짜
        }

        FinishLine.push_back(Finish);
        Finish = 0;
    }
    int iMax_Size = FinishLine.size();
    for (int i = 0; i < FinishLine.size()-1;)
    {
        if (FinishLine[i] >= FinishLine[i + 1])
        {
            int j = i + 1;

            while (FinishLine[i] >= FinishLine[j])
            {
                
                
                Update++;
                FinishLine.erase(FinishLine.begin() + j);
                if (i == FinishLine.size()-1)
                {
                    j--;
                    Fish = false;
                    break;
                    
                }

            }
            Update++;
            answer.push_back(Update);
            Update = 0;
            i = j;
        }
        else if (FinishLine[i] < FinishLine[i + 1])
            {
                Update++; //추가되는 기능 갯수
                answer.push_back(Update);
                Update = 0;
                i++;
            }


        if (FinishLine[i] == FinishLine.back() && Fish)
        {
            Update++; //추가되는 기능 갯수
            answer.push_back(Update);
            Update = 0;

        }

    }

    return answer;
}
int main()
{
    vector<int> i;
    vector<int> j;
    i.push_back(95);
    i.push_back(90);
    i.push_back(99);
    i.push_back(99);
    i.push_back(80);
    i.push_back(99);

    j.push_back(1);
    j.push_back(1);
    j.push_back(1);
    j.push_back(1);
    j.push_back(1);
    j.push_back(1);


    solution(i, j);

}


#endif // 수준차이 미쳣네
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day; //몇일
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i) // 진행도의 갯수에 따라
    {
        day = (99 - progresses[i]) / speeds[i] + 1; // 남은 진행도에서 달성속도를 나누기 => 남은 날 구하기

        if (answer.empty() || max_day < day) // 비어있거나, 현재 구해진 남은 날이 최대 날보다 클 경우
            answer.push_back(1);
        else
            ++answer.back(); // 다음

        if (max_day < day) // 최대 날 초기화
            max_day = day;
    }

    return answer;
}
