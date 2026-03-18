// grades_vec.cpp

#include <iostream>
#include <string>
#include <ios>
#include <iomanip> // input output 수정 // 실수 1.33333333 -> 원하는 소숫점 자리까지 자를 수 있음
#include <vector>
#include <algorithm> // sort()

using namespace std;

int main(void) {
	/*
		한 과목에서
		- 중간고사 = 20 %
		- 기말고사 = 40 %
		- 평균과제 = 40 %
	*/
	// 학생의 이름을 묻고 입력받기


	int option = 0;
	string name = "", fname, lname; //main 함수 범위 (scope)
	double att = 0.1,
		mid = 0.3,
		fin = 0.3,
		hw = 0.25,
		project = 0.05;



	while (option != 1 && option != 2) {
		cout << "Select country : 1. Korea, 2. USA : ";
		cin >> option;

		if (option == 1) { // Korea
			cout << "Name : ";
			cin >> name;
		}
		else if (option == 2) { // USA
			cout << "First name + Last name : ";
			cin >> fname >> lname;
			name = fname + " " + lname;
		}
		if (name != "") {
			cout << "Hello, " << name << " !" << endl;
		}

	} // while 끝


	// 중간고사와 기말고사 점수를 묻고 입력받기
	cout << "Midterm + Final grades : ";
	double midterm, final = 0;
	cin >> midterm >> final; // 45 65 => 45 줄 바꿈 65

	// 과제 점수를 물음
	cout << "All Hw grades + EOF : "; // EOF : End Of File : CTRL + D, CTRL + Z

	vector <double> homework;

	// 입력을 위한 변수
	double in; // 임시 변수 (과제 읽을 때 만)

	// 불변성 : 지금까지 count 개 점수를 입력받았으며
	// 입력받은 점수의 합은 sum

	while (cin >> in) {
		homework.push_back(in);
	}

	// 과제 점수의 입력 유무를 확인
	typedef vector <double> ::size_type  vec_sz;
	vec_sz size = homework.size(); // 배열 크기
	if (size == 0) {
		cout << endl << "ERROR : Enter your HW grades ! Try again !"
			<< endl;
		return 1; // 오류 코드
	}

	// 점수를 정렬
	sort(homework.begin(), homework.end());
	
	// 정렬한 점수를 출력
	cout << "Sorted grades : ";
	for (int i = 0; i < homework.size(); i++) {
		cout << homework[i] << " ";
	}
	cout << endl;
	
	// 과제 점수의 중앙값을 구함
	vec_sz mid_pt = size / 2;
	double median;
	median = (size % 2 == 0) ? // if 조건
		(homework[mid_pt] + homework[mid_pt - 1]) / 2 : // if 참
		homework[mid_pt]; // else 거짓

	// 추가 : 중앙값과 평균 비교하기
	double average, sum = 0;
	for (int i = 0; i < homework.size(); i++) {
		sum += homework[i];
	}
	average = sum / homework.size();
	

	// 결과를 출력
	streamsize prec = cout.precision();
	// 나중에 이것을 사용하고
	// 정밀도 초기화

	/*cout << name << " 's Final grade : " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;*/



	cout << name << " 's Final grade (중앙값) : "
		<< (att * 100)
		+ (mid * midterm)
		+ (fin * final)
		+ (hw * median)
		+ (project * 100)
		<< endl;

	cout << name << " 's Final grade (평균) : "
		<< (att * 100)
		+ (mid * midterm)
		+ (fin * final)
		+ (hw * average)
		+ (project * 100)
		<< endl;

	return 0;
}