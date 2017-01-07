

/*�ҵĵ��Ե�����������⣬��ʦ���ĺ����Լ��Ķ��򲻿��������Ҿ���windows��c++��ĳ���*/


#include <iostream> 
#include <string>
#include <math.h>
using namespace std;


/*���tʱ�̵����꣨x,y��*/
double posx, posy ,v, ap, as;

double x3=0, y3=0, t;  //���Ե�ǰΪ��0��0��

double t1, t2, t3;  //ʱ��ڵ�
double s1, s2, s3;  //λ�ƽڵ�

double ss, s;  //��ǰλ�ƣ���λ��

bool new_cmd = false;

void new_cmd1() {
	cout << "λ��x" << endl;
	cin>> posx;
	cout << "λ��y" << endl;
	cin >> posy;
	cout << "�ٶ�" << endl;
	cin >> v;
	cout << "���ٶ�" << endl;
	cin >> ap;
	cout << "���ٶ�" << endl;
	cin >> as;
}

void task_trajectory_generator() {
	t1 = v / ap;
	t2 = v / as;
	s = sqrt((posx - x3)*(posx - x3) - (posy - y3)*(posy - y3));
	s1 = 0.5*ap*t1*t1;
	s2 = 0.5*as*t2*t2;
	s3 = s - s1 - s2;
	t3 = s3 / v;
}

void root(int tm) {
	if (tm < t1)
		ss = 0.5*ap*tm*tm;
	else if (tm < (t1 + t2))
		ss = s1 + v*(tm - t1);
	else
		ss = s1 + s2 + s3 - 0.5*as*(t1 + t2 + t3 - tm)*(t1 + t2 + t3 - tm);
}

void main(){
	t = 0;
	new_cmd1();
    task_trajectory_generator();
	while (t < t1 + t2 + t3) {
		root(t);
		cout << "��ǰt=" << t << ",λ��Ϊs=" << ss << endl;
		t = t + 0.1;
	}
	new_cmd = true;
	cout << "new_cmd=" << new_cmd;
}