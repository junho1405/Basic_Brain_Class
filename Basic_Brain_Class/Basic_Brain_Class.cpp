#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;

class plus_quiz
{
	int score = 0;
	int quiz_count = 1;
	
public:
	void easy()
	{
		srand(time(0));
		int score =0;
		while (quiz_count < 10)
		{
			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << "+" << y << endl;
			cin >> answer;
			if (x + y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}

};

//말랑말랑두뇌교실
int main()
{
	plus_quiz quiz1;
	quiz1.easy();
}