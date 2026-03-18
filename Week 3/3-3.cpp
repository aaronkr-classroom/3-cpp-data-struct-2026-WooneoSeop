// 3-3 입력에서 각 단어가 등장한 횟수를 세는 프로그램을 작성해보세요.

#include <iostream>
#include <string>
#include <ios>
#include <iomanip> 
#include <vector>
#include <algorithm> 

using namespace std;


int main(void) {

	vector <string> words;
	string s;

	cout << "문장을 입력한 후 Ctrl + Z 입력 : ";

	while (cin >> s) {
		words.push_back(s);
	}

	cin.clear();

	string search;
	cout << "단어를 입력하세요 : ";
	cin >> search;


	sort(words.begin(), words.end());
	
	int count = 0;

	for (int i = 0; i < words.size(); i++) {
		if (words[i] == search) {
			++count;
		}
	}

	cout << search << " : " << count << " 개" << endl;
	
	return 0;

}
