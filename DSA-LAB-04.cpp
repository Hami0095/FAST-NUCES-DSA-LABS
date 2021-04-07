#include<iostream>
#include"stack.cpp"
#include<string>
#include<vector>

using namespace std;

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int divide(int a, int b) {
	return a / b;
}
int mul(int a, int b) {
	return a * b;
}

void task2() {
	Stack<int> s1;

	string expression = "=*+69-31";
	int i = expression.size();
	char a = expression[i];
	while (a != '=') {
		if (!Operator(a))
		{
			char* temp = &a;
			int c = atoi(temp);
			//int c = int(a[i]);
			s1.Push(c);

		}
		else {
			int c, b;
			c = s1.Peek();
			s1.Pop();
			b = s1.Peek();
			s1.Pop();
			if (a == '+')
				c = add(c, b);
			else if (a == '-')
				c = sub(c, b);
			else if (a == '*')
				c = mul(c, b);
			else if (a == '/')
				c = divide(c, b);

			s1.Push(c);
		}

		i--;
		a = expression[i];
	}

	int result = s1.Peek();
	cout << "Result : " << result << endl;
}


void task1() {
	/*
	Write a function that evaluate a postfix expression using stack. You are given pseudo code to
	help you.
	Sample input: 6 3 + 2 *=
	check 6 is operator? no then push
	push 6, push 3
	+ is operator, then pop previous two elements and operate it
	and push the result in stack
	then push 2
	then again operator * means to pop previous two terms and apply operation and 
	store the result in stack (push)
	continue doing till operator != '='
	Sample Output: 18
	*/

	Stack<int> s1;
	
	string expression = "63+2*=";
	//int i = expression.size();
	int i = 0;
	char a = expression[i];
	while (a != '=') {
		if (!Operator(a)) 
		{
			char* temp = &a;
			int c = atoi(temp);
			//int c = int(a[i]);
			s1.Push(c);

		}
		else {
			int c, b;
			c = s1.Peek();
			s1.Pop();
			b = s1.Peek();
			s1.Pop();
			if (a == '+')
				c = add(c, b);
			else if (a == '-')
				c = sub(c, b);
			else if (a == '*')
				c = mul(c, b);
			else if (a == '/')
				c = divide(c, b);

			s1.Push(c);
		}

		i++;
		a = expression[i];
	}

	int result = s1.Peek();
	cout << "Result : " << result << endl;
}
bool Operator(char a) {

	if (a == '+' || a == '-' || a == '*' || a == '/') {
		return true;
	}
	else
		return false;
}


void task3() {

	/*
	* input: 1+2*3
	  Sample Output: 123*+
	*
	// i will be checking the element whether it is operator
	// if not, it will be pushed into stack
	// and if the element is operator, push into operator_vector
	// then after till the end,
	// now in operator vector, find - + * / and throw into stack
	*/
	vector<char> op_Vector;
	
	Stack<char> s;

	string expression = "1+2*3";

	for (int i = 0; i < expression.size(); i++) {
		char a = expression[i];
		if (!Operator(a)) {
			s.Push(a);
		}
		else {
			op_Vector.push_back(a);
		}
	}
	int countM, countD, countA, countS;
	countM = countD = countA = countS = 0;
	// Check krna ha k operators kon kon sy hain?
	for (int i = 0; i < op_Vector.size(); i++) {
		if (op_Vector[i] == '*') {
			countM++;
		}
		if (op_Vector[i] == '/') {
			countD++;
		}
		if (op_Vector[i] == '-') {
			countS++;
		}
		if (op_Vector[i] == '+') {
			countA++;
		}
	}
	// pushing operators:
	int i = 0;
	while (countD != 0) {
		s.Push('/');
		countD--;
	}
	while (countM != 0) {
		
		s.Push('*');
		countM--;
	}
	while (countA != 0) {
		s.Push('+');
		countA--;
	}
	while (countS != 0) {				
		s.Push('-');
		countS--;
	}
	
	s.Print();

}




int main() {

	cout << "Task1 : ";
	task1();
	cout << "Task2 : ";
	task2();
	cout << endl;
	cout << "TASK3 : ";
	task3();

	;return 0;
}
