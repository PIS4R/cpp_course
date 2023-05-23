#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	Stack s1;
	Stack s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s2.push(20);
	s2.push(29);
	s2.push(39);
	s2.push(49);
	s2.push(59);
	s2.push(69);
	s2.push(79);
	s2.push(89);
	printf("%d %d\n", s1.pop(), s2.pop());
	printf("%d %d\n", s1.pop(), s2.pop());
	printf("%d %d\n", s1.pop(), s2.pop());
	printf("%d %d\n", s1.pop(), s2.pop());
	printf("%d %d\n", s1.pop(), s2.pop());

	s1.clear();
	s2.clear();
	return 0;
}
