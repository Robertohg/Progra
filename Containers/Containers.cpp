#include <iostream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stack>
#include <fstream>
#include <cstdlib>  
#include <set>
#include <map>

int key = 0;
std::stack<std::string> mStack;
std::queue<std::string> mQueue;
std::deque<std::string> mDeque;
std::set<std::string> mSet;
std::multiset<std::string> mMultiSet;
std::map<int, std::string > mMap;
std::multimap<int, std::string> mMultiMap;
std::vector<std::string> mVector;

std::string get_csv_column(std::ifstream& in)
{
	std::string col;
	unsigned quotes = 0;
	char prev = 0;
	bool finis = false;
	for (int ch; !finis && (ch = in.get()) != EOF; ) {
		switch (ch) {
		case '"':
			++quotes;
			break;
		case ',':
			if (quotes == 0 || (prev == '"' && (quotes & 1) == 0)) {
				finis = true;
			}
			break;
		default:;
		}
		col += prev = ch;
	}
	return col;
}
void print(int columna,int x, int y) {
	switch (columna)
	{
	case 0:
	{	int it = mStack.size();
		
		for (; it >= x; it--) {
			if (it <= y) {
				std::cout << mStack.top() << std::endl;
			}
			mStack.pop();
		}
		break;
	}
	case 1:
	{	
		for (int i = 0; i <= y; i++) {
			if (i >= x) {
				std::cout << mQueue.front() << std::endl;
			}
			mQueue.pop();
		}
		break;
	}
	case 2: 
	{
		for (; x <= y; x++) {
			std::cout << mDeque[x-1] << std::endl;
		}
		break;
	}
	case 3:
	{	int i = 0;
		for (auto it = mSet.begin(); it != mSet.end(); ++it)
			if (i <= x && i >= y) {
				std::cout << *it<<std::endl;
			}	
		break;
	}
	case 4:
	{
		int i = 0;
		for (auto it = mMultiSet.begin(); it != mMultiSet.end(); ++it)
			if (i <= x && i >= y) {
				std::cout << *it << std::endl;
			}
		break;
	}
	case 5: {
		for (; x <= y; x++) {
			std::cout << mMap[x] << std::endl;
		}
		break;
	}
	default:
		break;
	}
}

void picker(std::string st, int columna) {
	switch (columna)
	{
	case 0:
	{
		mStack.push(st);
		break;
	}
	case 1:
	{
		mQueue.push(st);
		break;
	}
	case 2:
	{
		mDeque.push_back(st);
		break;
	}
	case 3:
	{
		mSet.insert(st);
		break;
	}
	case 4:
	{
		mMultiSet.insert(st);
		break;
	}
	case 5:
	{
		mMap.insert(std::pair<int, std::string>(key, st));
		key++;
		break;
	}
	case 6:
	{
		mMultiMap.insert(std::pair<int, std::string>(key, st));
		key++;
		break;
	}
	case 7:
	{
		mVector.push_back(st);
		break;
	}
	default:
		break;
	}
}

int main() {
	std::string comments;
	std::string duration;
	std::string events;
	std::string film_date;
	std::string languages;
	std::string main_speaker;
	std::string name;
	std::string num_speaker;
	std::string publish_date;
	char comma;
	int contenedor;
	int columna =0;
	int iter=0;
	int x, y;




	
	std::cout << "Elija el contenedor" << std::endl;
	std::cout << "Stack[0], Queue[1], Deque[2], Set[3], Multiset[4], Map[5], Multimap[6], Vector[7]" << std::endl;
	std::cin >> contenedor;
	std::cout << "Elija una columna" << std::endl;
	std::cout << "comments[0], duration[1], event[2], film_date[3], languages[4], main_speaker[5], name[6], num_speaker[7], published_date[8]" << std::endl;
	std::cin >> columna;
	std::string line;
	
	std::ifstream in("ted_main2.csv");
	if (!in) {
		std::cout << "Open error :(" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (std::string col; in; ) {
		if (iter == columna) {
			col = get_csv_column(in);
			col.pop_back();
			picker(col, columna);
		}
		iter < 9 ? iter++ : iter = 0;

	}

	std::cout << "Ingrese un X y un Y" << std::endl;
	std::cout << "X:";
	std::cin >> x;
	std::cout << "Y:";
	std::cin >> y;
	print(contenedor, x, y);


	if (!in && !in.eof()) {
		std::cout << "Read error :(" << std::endl;
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);



	

	}