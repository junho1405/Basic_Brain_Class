#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;

class MiniGame
{
private:
public:
	virtual void play() = 0;
	virtual ~MiniGame() {}
};



class Plus_Quiz
{
	int score = 0;
	int quiz_count = 1;

public:
	void easy()
	{
		cout << "easy모드" << endl;
		int score = 0;
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
	void nomal()
	{
		cout << "nomal모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 99 + 1;
			int y = rand() % 99 + 1;
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
	void hard()
	{
		cout << "hard모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 999 + 1;
			int y = rand() % 999 + 1;
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

}