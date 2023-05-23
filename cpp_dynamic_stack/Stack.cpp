#include "Stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Stack::Stack()
{
	
	this->top = 0;
	this->dane1 = (int*)calloc(0, sizeof(int));
	
}

Stack::~Stack()
{
	clear();
}

int Stack::push(int a)
{
	//Dynamically reallocated memory to prev elements + new element + '\0'
	tmp_dane1 = (int*)realloc(dane1, (sizeof(int)*top)+sizeof(int)+1);
	
	//Error handling
	if (tmp_dane1 != NULL) {
		dane1 = tmp_dane1;
	} else{
		printf("The reallocation went unsuccesfull.\nCheck 20:Stack.cpp:Stack::push\n");
		return 0;
	}
	
	//push element to the top of the stack
	*(dane1 + this->top) = a;
	this->top = this->top + 1;
	return 1;
	
}

int Stack::pop()
{
	//error handling when stack is empty
	if(this->top <= 0){
		printf("You try to pop items outside the scope of Stack.\nStack is probably empty\n");
		exit (0);
	}
	//resize the top value & return top element
	this->top = this->top - 1;
	return *(dane1 + this->top);

}

void Stack::clear()
{	
	//free the memory
	free(this->dane1);
	this->dane1 = NULL;
	this->top = 0;
}
