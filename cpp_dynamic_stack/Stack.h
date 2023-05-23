#define STACKSIZE 20

class Stack
{
public:
	Stack();
	~Stack();
	int push(int a);
	int pop();
	void clear();

private:
	int *tmp_dane1;
	int *dane1;
	int top;
	int dane[STACKSIZE];
};
