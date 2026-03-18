// 3-4. 입력에서 길이가 가장 긴 문자열의 길이와 길이가 가장 짧은 문자열의 길이를 알려주는 프로그램을 작성해보세요.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(void) {

	vector <string> str;
	string s;

	cout << "문장을 입력하세요 : ";

	while (cin >> s) {
		str.push_back(s);
	}
	
	typedef vector <string> ::size_type  vec_size;
	vec_size max = str[0].size();
	vec_size min = str[0].size();

	string longest = str[0];
	string shortest = str[0];

	for (int i = 0; i < str.size(); i++) {
		if (str[i].size() > max) {
			max = str[i].size();
			longest = str[i];
		}
		if (str[i].size() < min) {
			min = str[i].size();
			shortest = str[i];
		}
	}
	cout << "가장 긴 문자열은 "<< longest << "이며, 가장 긴 문자열의 길이 : " << max << endl;
	cout << "가장 짧은 문자열은 " << shortest << "이며, 가장 짧은 문자열의 길이 : " << min << endl;

	return 0;
}