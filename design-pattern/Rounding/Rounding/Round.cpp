#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

class  Process {
private:
	string name;
	int arriveTime;
	int lastTime;
	bool status;
public:
	Process() :name(""), arriveTime(0), lastTime(4), status(false){};
	Process(const string& name, int at, int lt, bool sta) :
		name(name), arriveTime(at), lastTime(lt), status(sta){};
	int getArriveTime() const
	{
		return arriveTime;
	}
	void subLastTime(){
		--lastTime;
	}
	int getLastTime(){
		return lastTime;
	}
	string getPname(){
		return name;
	}
	void finish(){
		status = "true";
	}
	bool getstatus(){
		return status;
	}

};




void inputProcess(deque<Process>& round){
	string name;
	int arriveTime = 0;
	int lastTime = 0;
	bool status = false;
	int count = 0;
	auto insert = back_inserter(round);
	cout << "please enter the number of process: -1 to exit: ";
	cin >> count;
	while (count > 0) {
		cout << "process name: ";
		cin >> name;
		cout << "arriveTime: ";
		cin >> arriveTime;
		cout << "lastTime: ";
		cin >> lastTime;
		--count;
		Process p(name, arriveTime, lastTime, false);
		round.push_back(p);
		cout << endl;
	}
}

void sortByArrivetime(deque<Process>& roundList){
	sort(roundList.begin(), roundList.end(), [](const Process& p1, const Process& p2)
	{return p1.getArriveTime() < p2.getArriveTime(); });
}


void runProcess(deque<Process>& roundList, deque<Process>::iterator iter){
	int clock = 1;
	int processNum = roundList.size();//��¼��ǰδ��ɽ�����
	while (processNum != 0) {
		while (iter->getstatus()) {//����ƶ����Ľ��������,���߻�û�е���,�����ƶ�һ��
			if (++iter == roundList.end()) {
				iter = roundList.begin();
				cout << "back to begin now the queue  contain:  ";//��ӡÿһ�ֵ�Ԫ��
				for (Process &elem : roundList) {
					if (elem.getstatus() == false && elem.getArriveTime() <= clock)
						cout << elem.getPname() << " ";
				}
				cout << endl;
			}
		}
		if (clock <= iter->getArriveTime()) {
			iter = roundList.begin();
			clock++;
			continue;
		}
		iter->subLastTime();//��ǰʱ��Ƭ�ݼ�

		//������״̬�Ĵ���
		if (0 >= iter->getLastTime()) {//�ж����н���
			(*iter).finish();
			cout << (*iter).getPname() << " has finished \n";
			processNum--;
		}
		else {
			cout << "run  " << iter->getPname();
			if (++iter != roundList.end()) {
				cout << "  lastime-1" << endl;
			}
			else {
				iter = roundList.begin();
				cout << "  lastime-1 " << endl;
				cout << "back to begin now the queue  contain:  ";//��ӡÿһ�ֵ�Ԫ��
				for (Process &elem : roundList) {
					if (elem.getstatus() == false && elem.getArriveTime() <= clock)
						cout << elem.getPname() << " ";
				}
				cout << endl;

			}
		}
	}
}

int main(){
	deque<Process> roundList;
	inputProcess(roundList);
	sortByArrivetime(roundList);
	auto iter = roundList.begin();
	runProcess(roundList, iter);
	system("pause");
}