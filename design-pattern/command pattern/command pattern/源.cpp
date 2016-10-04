#include<iostream>
#include<memory>
#include<stack>
#include<list>
using namespace std;

class Command {
public:
	virtual void Execute() = 0;
	virtual void undo() = 0;
};

class CommandManager {
private:
	list<shared_ptr<Command> > undoList;
	list<shared_ptr<Command> > redoList;
	int undocnt;
public:
	CommandManager(int undocount = 5) :undocnt(undocount){};
	void executeCommand(shared_ptr<Command> c){
		c->Execute();
		undoList.push_back(c);
		if (undoList.size()!= 0&&undoList.size()> undocnt) {
			undoList.erase(undoList.begin());
		}
		redoList.clear();
	}

	void undo(){
		if (undoList.size() <= 0)
			return;
		shared_ptr<Command> cmd = undoList.back();
		cmd->undo();
		undoList.pop_back();
		redoList.push_back(cmd);
	}
	void redo(){
		if (redoList.size() <= 0)
			return;
		shared_ptr<Command> cmd = redoList.back();
		cmd->Execute();
		redoList.pop_back();
		undoList.push_back(cmd);
	}
};
class Recever{
public:
	void doSomething(){
		cout << "has reveived the message\n";
	}
	void undoSomething(){
		cout << "undo the command\n";
	}
};

class CommandSub1 :public Command {
private:
	Recever receiver_;
public:
	CommandSub1(const Recever &receiver) :receiver_(receiver){}
	virtual void Execute(){
		cout << "exe process 1: \n";
		this->receiver_.doSomething();
	}
	virtual void undo(){
		cout << "undo process 1: \n";
		this->receiver_.undoSomething();
	}
};

class CommandSub2 :public Command {
private:
	Recever receiver_;
public:
	CommandSub2(const Recever &receiver) :receiver_(receiver){}
	virtual void Execute(){
		cout << "exe process 2: \n";
		this->receiver_.doSomething();
	}
	virtual void undo(){
		cout << "undo process 2: \n";
		this->receiver_.undoSomething();
	}
};



int main(){
	Recever eligah;
	shared_ptr<Command> c1 = shared_ptr<Command>(new CommandSub1(eligah));	
	shared_ptr<Command> c2 = shared_ptr<Command>(new CommandSub2(eligah));
	
	CommandManager cmdmanager;
	cmdmanager.executeCommand(c1);
	cmdmanager.executeCommand(c2);
	cmdmanager.undo();
	cmdmanager.undo();
	cmdmanager.redo();


}