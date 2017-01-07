

/*我的电脑的虚拟机有问题，老师您的和我自己的都打不开，所以我就在windows用c++编的程序*/


#include <iostream> 
#include <string>
#include <math.h>
using namespace std;


/*输出t时刻的坐标（x,y）*/
double posx, posy ,v, ap, as;

double x3=0, y3=0, t;  //测试当前为（0，0）

double t1, t2, t3;  //时间节点
double s1, s2, s3;  //位移节点

double ss, s;  //当前位移，总位移

bool new_cmd = false;

void new_cmd1() {
	cout << "位置x" << endl;
	cin>> posx;
	cout << "位置y" << endl;
	cin >> posy;
	cout << "速度" << endl;
	cin >> v;
	cout << "加速度" << endl;
	cin >> ap;
	cout << "减速度" << endl;
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
		cout << "当前t=" << t << ",位移为s=" << ss << endl;
		t = t + 0.1;
	}
	new_cmd = true;
	cout << "new_cmd=" << new_cmd;
}