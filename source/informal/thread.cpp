#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <queue>
#include <curses.h>
using namespace std;

void print(queue<char>* list)
{
	int cnt = 0;
	string str = "1234567890\r";
	while(cnt<10)
		for(const auto& it: str)
		{
			if(list->empty())
			{
				cout<<it<<" ";
				cout.flush();
			}
			else 
			{
				cnt++;
				cout<<'\b';
				cout<<list->front()<<' ';
				list->pop();
			}
			this_thread::sleep_for (std::chrono::seconds(1));
		}
}

int main()
{
	queue<char>* printList = new queue<char>;
	char ch;

	thread go(print, printList);
	go.detach();

	while( (ch = cin.get()) != 'z' )
		printList->push(ch);
	delete printList;
	return 0;
}
