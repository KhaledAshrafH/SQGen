#include <iostream>
#include<cstring>
#include<string>
using namespace std;

//Classes Declaration

//Class MyList (Template and Abstract) 
template<typename T>
class MyList {
protected:
	int itsSize;
	T * elems;
public:
	MyList(int size = 10); //parameterized constructor
	MyList() {}; //default constructor
	~MyList() //destructor
	{
		delete[]elems; //deallocate elems
	}
	//inline function to return itsSize
	int getSize() {
		return itsSize;
	}
	
	//Virtual Functions need to impelement in inherited class
	virtual void addElem(T element) = 0; //adds an element
	virtual T& getElem() =0; //returns an element, after removing it from the array
	virtual bool isEmpty() = 0; //returns true if the array is empty
	virtual bool isFull() = 0; //returns true if the array is full
	virtual void clearItems() = 0; //which empties the array
	
	//Virtual Function will override in inherited class
	virtual void PrintElements(){
		cout << "All Elements" << endl;
	}

};

//Class MyStack (Template)
template<typename T>
class MyStack: public MyList<T> {
	int k=-1; //to control in size of conditions
public:
	MyStack(int size); //parameterized constructor
	MyStack(); //default constructor
	void addElem(T element); //Function overriding to add an element
	void PrintElements(); //Function overriding to print elements
	T& getElem(); //Function overriding to return an element, after removing it from the array
	bool isEmpty(); //Function overriding to return true if the array is empty
	bool isFull(); //Function overriding to returns true if the array is full
	void clearItems(); //Function overriding to empty the array
	
};

//Class MyQueue (Template)
template<typename T>
class MyQueue : public MyList<T> {
	int k = -1;
public:
	MyQueue(int size); //parameterized constructor
	MyQueue(); //default constructor
	void addElem(T element); //Function overriding to add an element
	void PrintElements(); //Function overriding to print elements
	T& getElem(); //Function overriding to return an element, after removing it from the array
	bool isEmpty(); //Function overriding to return true if the array is empty
	bool isFull(); //Function overriding to returns true if the array is full
	void clearItems(); //Function overriding to empty the array

};

//Class Rectangle
class Rectangle {
private:
	int length, width;
public:
	Rectangle() :length(0), width(0) {} //default constructor and initialize length and width by 0
	Rectangle(int len, int wid); //parameterized constructor
	class negativeSize {
		//Empty Class
	};
	
	//Setters and Getters Functions
	void setLength(int l);
	int getLength() {
		return length;
	}
	void setWidth(int w);
	int getWidth() {
		return width;
	}
	
	//return Area of rectangle
	int PrintArea() {
		return length * width;
	}
	
	//print rectangle by cout
	friend ostream& operator<<(ostream& output, Rectangle& r);

};

//Main Function 

int main()
{
	endingpointHome: //To return in this point if user entered wrong input
	char ch; //to store (S OR Q)
	cout << "Would you like to use a stack or a queue (S/Q)?" << endl;
	cin >> ch;
	
	//To choose S or Q
	switch (ch) {

	//in case of user want to use Stack Methods
	case 's':
	case 'S': {
		EndingpointS: //To return in this point if user entered wrong input
		int selectNum, size, num;
		cout << "Would you like to store integers, strings, or rectangles (1,2, or 3)?" << endl;
		cin >> selectNum;

		//check if user enter wrong input or not
		if (selectNum < 1 || selectNum>3) {
			cout << "Wrong Input! Try again." << endl;
			goto EndingpointS; //return to point EndingpointS
		}

		//Exception if user entered negative or zero number of elements
		try {
			cout << "How many items to store?" << endl;
			cin >> size;
			if (size <= 0) throw exception();
		}
		catch(exception e){
			cout << "Wrong Input! please enter positive number : ";
			cin >> size;
			if (size <= 0) {
				cout << "Wrong Input!Try again." << endl;
				goto EndingpointS; //return to point EndingpointS
			}
		}

		//To choose 1,2, or 3
		switch (selectNum) {
		
		//if user want to store integers
		case 1:{
			MyStack<int>*stack=new MyStack<int>(size); 
			for (int i = 0; i < size; i++) {
				
				//Exception if user entered string insted of integer
				try {
					cout << "Enter Num:";
					cin >> num;
					if (cin.fail()) { //if input is string (cin.fail()) will return true
						throw exception();
					}
					stack->addElem(num);
				}
				catch (exception ex) {
					cout << "Wrong String Input-->will enter 0" << endl;
					cin.clear(); //to clear the error cin
					string str;
					cin >> str;
					stack->addElem(0);
				}

			}
			cout << endl;
			stack->PrintElements();
			return 0;
		}

		//if user want to store Strings
		case 2:{
			string str;
			MyStack<string>*stack = new MyStack<string>(size);
			for (int i = 0; i < size; i++) {
				cout << "Enter String:";
				cin >> str;
				stack->addElem(str);
			}
			cout << endl;
			stack->PrintElements();
			return 0;
		}

		//if user want to store Rectangles
		case 3:{
			int length,width;
			MyStack<Rectangle>*stack = new MyStack<Rectangle>(size);
			Rectangle copyRects; //to store rects objects
			for (int i = 0; i < size; i++) {
				cout << "Enter length and width space separated:";
				cin >> length>>width;
				
				//Exception if user entered a negative length or width
				try {
					Rectangle rects(length, width);
					copyRects = rects;
					stack->addElem(copyRects);
				}
				catch(Rectangle::negativeSize){
					cout << "Wrong length or width entering 0 and 0" << endl;
					Rectangle rects(0, 0);
					copyRects = rects;
					stack->addElem(copyRects);
				}

			}
			cout << endl;
			stack->PrintElements();
			return 0;
		}
		
		//if user enter anothor input
		default: {
			cout << "Wrong Input! Try again." << endl;
			goto EndingpointS; //return to point EndingpointS
		}

		}
	
	}

	//in case of user want to use Queue Methods
	case 'q':
	case 'Q': {
		EndingpointQ: //To return in this point if user entered wrong input
		int selectNum, size, num = 0;
		cout << "Would you like to store integers, strings, or rectangles (1,2, or 3)?" << endl;
		cin >> selectNum;

		//check if user enter wrong input or not
		if (selectNum < 1 || selectNum>3) {
			cout << "Wrong Input! Try again." << endl;
			goto EndingpointQ; //return to point EndingpointQ
		}

		//Exception if user entered negative or zero number of elements
		try {
			cout << "How many items to store?" << endl;
			cin >> size;
			if (size <= 0) throw exception();
		}
		catch (exception e) {
			cout << "Wrong Input! please enter positive number : ";
			cin >> size;
			if (size <= 0) { 
				cout << "Wrong Input!Try again." << endl;
				goto EndingpointQ; //return to point EndingpointQ
			}
		}

		//To choose 1,2, or 3
		switch (selectNum) {

		//if user want to store integers
		case 1: {
			MyQueue<int>*queue = new MyQueue<int>(size);
			for (int i = 0; i < size; i++) {
				
				//Exception if user entered string insted of integer
				try {
				cout << "Enter Num:";
				cin >> num;
					if (cin.fail()) { //if input is string (cin.fail()) will return true
						throw exception(); }
					queue->addElem(num);
				}
				catch (exception ex) {
					cout << "Wrong String Input-->will enter 0" << endl;
					cin.clear(); //to clear the error cin
					string str;
					cin >> str;
					queue->addElem(0);
				}

			}
			cout << endl;
			queue->PrintElements();
			return 0;
		}

		//if user want to store Strings
		case 2: {
			string str;
			MyQueue<string>*queue = new MyQueue<string>(size);
			for (int i = 0; i < size; i++) {
				cout << "Enter String:";
				cin >> str;
				queue->addElem(str);
			}
			cout << endl;
			queue->PrintElements();
			return 0;
		}

		//if user want to store Rectangles
		case 3: {
			int length, width;
			MyQueue<Rectangle>*queue = new MyQueue<Rectangle>(size);
			Rectangle copyRects;
			for (int i = 0; i < size; i++) {
				cout << "Enter length and width space separated:";
				cin >> length >> width;
				
				//Exception if user entered a negative length or width
				try {
					Rectangle rects(length, width);
					copyRects = rects;
					queue->addElem(copyRects);
				}
				catch (Rectangle::negativeSize) {
					cout << "Wrong length or width entering 0 and 0" << endl;
					Rectangle rects(0, 0);
					copyRects = rects;
					queue->addElem(copyRects);
				}

			}
			cout << endl;
			queue->PrintElements();
			return 0;
		}

		//if user enter anothor input 
		default: {
			cout << "Wrong Input! Try again." << endl;
			goto EndingpointQ; //return to point EndingpointQ
		}

		}

	}

	//if user enter anothor input Not S or Q
	default: {
		cout << "Wrong Input! Try again." << endl;
		goto endingpointHome; //return to point endingpointHome
	}

	}
	
	return 0;
}

//Classes Implementation

//Class MyStack

//parameterized constructor
template<typename T>
MyStack<T>::MyStack(int size):MyList<T>::MyList(size)
{
}

//default constructor
template<typename T>
MyStack<T>::MyStack()
{
}

//add element in array
template<typename T>
void MyStack<T>::addElem(T element)
{
	++k; //become zero in first time and will icrease by one
	MyList<T>::elems[k] = element;
}

//print elements of array
template<typename T>
void MyStack<T>::PrintElements()
{
	MyList<T>::PrintElements();
	for (int i = MyList<T>::itsSize-1 ; i >= 0; i--) {
		cout << "Element-->" << MyList<T>::elems[i] << endl;
	}
	cout << endl;
}

//return an element, after removing it from the array
template<typename T>
T& MyStack<T>::getElem()
{
	T elementDeleted;
	elementDeleted = MyList<T>::elems[k]; //the last element in array
	MyList<T>::itsSize--; //decrease size array by one to delete the last element
	return elementDeleted;
}

//check if the array is empty
template<typename T>
bool MyStack<T>::isEmpty()
{
	return (k == -1); //return true if array is empty
}

//check if the array is full
template<typename T>
bool MyStack<T>::isFull()
{
	return !(k >= MyList<T>::itsSize); //return true if array is full
}

//empty the array
template<typename T>
void MyStack<T>::clearItems()
{
	k = -1;
	delete[] MyList<T>::elems;
	MyList<T>::elems = new T[MyList<T>::itsSize];
}

//Class MyQueue

//parameterized constructor
template<typename T>
MyQueue<T>::MyQueue(int size):MyList<T>::MyList(size)
{
}

//default constructor
template<typename T>
MyQueue<T>::MyQueue()
{
}

//add element in array
template<typename T>
void MyQueue<T>::addElem(T element)
{
	++k; //become zero in first time and will icrease by one
	MyList<T>::elems[k] = element;
}

//print elements of array
template<typename T>
void MyQueue<T>::PrintElements()
{
	MyList<T>::PrintElements();
	for (int i = 0; i < MyList<T>::itsSize; i++) {
		cout <<"Element-->"<< MyList<T>::elems[i] << endl;
	}
	cout << endl;
}

//return an element, after removing it from the array
template<typename T>
T & MyQueue<T>::getElem()
{
	T elementDeleted;
	elementDeleted = MyList<T>::elems[k]; //the last element in array
	MyList<T>::itsSize--; //decrease size array by one to delete the last element
	return elementDeleted;
}

//check if the array is empty
template<typename T>
bool MyQueue<T>::isEmpty()
{
	return (k == -1); //return true if array is empty
}

//check if the array is full
template<typename T>
bool MyQueue<T>::isFull()
{
	return !(k >= MyList<T>::itsSize); //return true if array is full
}

//empty the array
template<typename T>
void MyQueue<T>::clearItems()
{
	k = -1;
	delete[] MyList<T>::elems;
	MyList<T>::elems = new T[MyList<T>::itsSize];
}

//Class Rectangle

//to print rectangle object
ostream & operator<<(ostream & output, Rectangle & r)
{
	output << "Length=" << r.getLength() << ",Width=" << r.getWidth() << ",Area=" << r.PrintArea() << endl;
	return output;
}

//parameterized constructor
Rectangle::Rectangle(int len, int wid)
{
	if ((len >= 0) && (wid >= 0)) {
		length = len;
		width = wid;
	}
	else {
		length = 0;
		width = 0;
		throw negativeSize();
	}
}

//to set length of rectangle
void Rectangle::setLength(int l)
{
	if (l > 0) length = l;
	else {
		length = 0;
		throw negativeSize();
	}
}

//to set width of rectangle
void Rectangle::setWidth(int w)
{
	if (w > 0) width = w;
	else {
		width = 0;
		throw negativeSize();
	}
}

//Class MyList

//parameterized constructor to allocate size MyStack or MyQueue in Mylist and allocate dynamic allocation array
template<typename T>
MyList<T>::MyList(int size)
{
	itsSize = size;
	elems = new T[itsSize];
}