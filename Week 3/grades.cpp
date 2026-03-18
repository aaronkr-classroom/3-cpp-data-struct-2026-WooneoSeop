// grades.cpp

#include <iostream>
#include <string>
#include <ios>
#include <iomanip> // input output 수정 // 실수 1.33333333 -> 원하는 소숫점 자리까지 자를 수 있음


using std::cin; using std::cout;
using std::endl; using std::string;
using std::setprecision; //정밀도 설정
using std::streamsize;


int main(void) {
	/*
		한 과목에서
		- 중간고사 = 20 %
		- 기말고사 = 40 %
		- 평균과제 = 40 %
	*/
	// 학생의 이름을 묻고 입력받기

	
	int option=0;
	string name = "", fname, lname; //main 함수 범위 (scope)
	double att = 0.1,
		mid = 0.3,
		fin = 0.3,
		hw = 0.25,
		project = 0.05;



	while (option !=1 && option !=2) {
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
	double midterm, final, sum = 0;
	int count = 0;
	cin >> midterm >> final; // 45 65 => 45 줄 바꿈 65
	
	// 과제 점수를 물음
	cout << "All Hw grades + EOF : "; // EOF : End Of File : CTRL + D, CTRL + Z

	// 입력을 위한 변수
	double in; // 임시 변수 (과제 읽을 때 만)

	// 불변성 : 지금까지 count 개 점수를 입력받았으며
	// 입력받은 점수의 합은 sum

	while (cin >> in) {
		++count;
		sum += in;

	}

	// 결과를 출력
	streamsize prec = cout.precision();
	// 나중에 이것을 사용하고
	// 정밀도 초기화

	/*cout << name << " 's Final grade : " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * (sum / count)
		<< setprecision(prec) << endl;*/


	cout << name << " 's Final grade : " 
		<< (att * 100)
		+ (mid * midterm)
		+ (fin * final)
		+ (hw * (sum / count))
		+ (project * 100)
		<< endl;

	return 0;
}