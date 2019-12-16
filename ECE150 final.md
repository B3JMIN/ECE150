binary and hex convert Lab#5

algorithm:

**hex to decimal:** using ASCII table, minus 'A' + 10; just minus '0'

**decimal to binary(hex):** using cmath pow, dividing them with 2 or 16 first, and then set a variable to check the remainder:

larger than 10 and less than 10: ASCII table.

reverse cout the array as a string  

**bianry to decimal:** 

temp is the input value, every time find the remainder of temp % 10, and mutiply by 2, add them together, at the same time.

while(temp){

​	int last_digit = temp % 10;

​	temp = temp /10;

​	dec_value += last_digit * base;

​	base = base * 2;

}

**alert:** restrictions on arithmatic operators:

using right shift bitwise operator. 

set bin as an string for binary numbers.

bin = ((n & 1) == 0 ? '0' : '1') + bin;

n >> = 1

can use bitwise operator to find the numbers and use shift to construct, left shift of 1 by i == 2 raised to power i 





call stack from high address to lower address, data[-5] =3.14

:grey_question:

segmentation falut: exceeding array bounds when you want to access larger index.



2s complement: from LSB(least significant bit), looking for 0. flip all 1's until we got a 0

example: 01000 => 11000

use reference to return multiple return values: we can use a void and use reference parameter, so it can be called and chaned in main function or other somewhere else.

Assignment#4: find the top three most frequent intergers in array:

**Pointer**:

An interesting property of pointers is that they can be used to access the variable they point to directly. This is done by preceding the pointer name with the *dereference operator* (`*`)

& assign the address of variable to another variable

\*dereference operator:*value* pointered to by

opposite meaning:  An address obtained with 7 can be derefernced with \*

after the declaring of pointers, even though they are int, or char or double, they do have the same amount of memory reserved for them  declare \* is not the dereference operator.

declartion \* is different with \* in the dereference

pointer:

int \* array[10]

int \* p_a{&array[0]}

p_a[i] == array[i] both are address from 0 and incement the size of each element in the array 

why we need dynamic memory allocation: 

sometimes we want the value beyond the function scope

dynamic momory is actually strored in heap instead of stack 

application of dynamic memory: we can use new and delete to allocate or deallocate value in to the heap with value that not fit in stack.

deallocate heap memory: delete p_int; p_int = nullptr 

delete the point address but the vaue p_int is still there, but  

int p_a and double p_b always pointing to an address, which depends on the system, and its 8 bytes

read more and understand nullptr and how we unallocate the pointer

new int[10] in project we dont need to free it up 

pointer as local variable and return value 

**pointers and array**

main different: pointers can change but array cannot, both can increment 

cannot swap with pointer --> call stack //  only way is pass by reference.

local variables: void f(int \* ) and void g(\* &q ) first is pass by value, while the second is pass by reference. change in address for 1 not effective

the address from heap will pass to call stack as a value, and & can access the value on the call stack

when we set an array in heap, it is not initialized, so the value in this array can be any value.

p_m_value = new double;

p_b_value = new double;

and then we need to delete the pointer and deallocate them

**sorting algorithm:**

Binary search:

```c++
return (array[left] == sought_value) ? left: capacity;
# My code
int binary_sort(int i, int sorted_Array[],)
{
  
}
```

Inertion sort:

```c++
void insertion_sort(double array[], )
```

C++ templete 

use typename: template <typename T>

```c++
template <typename T1, typename T2>
void f(T1 x, T2 y);

```



Classes

class is literally local variable, any instances in this classs are also objects

**Linked List C++**

data is dynamic and we cannot predict the number of data

The way we use index in linked list is super stupid

dynamically allocation linked list 

```c++
// -> accesss member variable with a pointer arrow to a value
p_node -> value_;
```



**constructors:**

object-oriented program allow the author of a class to specify a function that must be called:

that function is called a constructor and has the *same name* as teh class itself.

It has *no return value* 

A constuctor is automatically called when an object is created.

one of the constructor called **Parameterized Constructors**

```c++
class Point{
  private:
  	int x, y;
  public:
   // there are some parameterized constructors
  Point(int x1, int y1)
  {
    x = x1;
    y = y1;
  }
 	// essentially constructors are functions
  int getX()
  {
    return x;
  }
  
  int getY()
  {
    return y;
  }
}
```

Throwing exceptions:



There can be nested class

```c++
// member initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) { }
    double area() {return radius*radius*3.14159265;}
};

// Cylinder can use the circle class: base
class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}
```

condition in c++ 

condition ? result1 : result2 , if the condition is true, return result1, false, return result2.



The arrow function and the dot in class 

```c++
struct Emploee{
  char first_name[16];
  int age;
}emp;
// Here we use the dot 
strcpy(emp.first_name, "zara")
// Here we use the arrow
strcpy(p_emp -> first_name, "zara")
  
// simply, To access members of a structure, use the dot operator.
// To access members of a strcuture through a pointer, use the arrow operator.
 
  

```

```c++
// ~Linked_list() is actually the destrcutor
// it is for in case user didnt delete the data in the linked list 
~Linked_list(){
  while(!empty())
  {
    clear();
  }
}
```

With class we can have an array with rectangle and different shape in the same array.



Operator overload:

which means that C++ has the ability to provide the operators with a special meaning for a data type.

```c++
/// examples are how we define [] operator
double Linked_list::operator[](std::size_t const &other) const{
  std::size_t k{0};
  Node *p_current_head{p_list_head};
  
  while(p_current_head!= nullptr){
    if(k == n){
      return p_current_head->get_value();
    }
    k++;
    p_current_head = p_current_head->get_next();
  }
  return 0;
}
```





Final exam: last year final, learn. /  some diff/

not cover inheritence. 

verctor 3d class not cover/ template cover / 

memory heap of class and member function

this give access to the address of member function /

print address of object A, challenge print within member function->this



Thersa's review session:

regex

call stack 

some concept: wild pointer : uninitialized pointer  // dangling point : 

memory leak: the pointer is not deallocated

Template allows the compiler to decide what the value is 

sorting alg linear search/ selecction sort /  insertion sort 



```c++
// C++ program for function overloading 
#include <bits/stdc++.h> 
  
using namespace std; 
class Geeks 
{ 
    public: 
      
    // function with 1 int parameter 
    void func(int x) 
    { 
        cout << "value of x is " << x << endl; 
    } 
      
    // function with same name but 1 double parameter 
    void func(double x) 
    { 
        cout << "value of x is " << x << endl; 
    } 
      
    // function with same name and 2 int parameters 
    void func(int x, int y) 
    { 
        cout << "value of x and y is " << x << ", " << y << endl; 
    } 
}; 
  
int main() { 
      
    Geeks obj1; 
      
    // Which function is called will depend on the parameters passed 
    // The first 'func' is called  
    obj1.func(7); 
      
    // The second 'func' is called 
    obj1.func(9.132); 
      
    // The third 'func' is called 
    obj1.func(85,64); 
    return 0; 
}  

```

Selection sort in c++

```c++
// C++ program for implementation of selection sort 
#include <bits/stdc++.h> 
using namespace std; 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	selectionSort(arr, n); 
	cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 


```

dangling pointer /  wild pointer / memory leak difference

 If a pointer is pointing to memory that is not owned by your program (except the null pointer) or an invalid memory, the pointer is called a dangling pointer.

wild pointer is pointer that has not been initialized 

**Dynamic allocation:**

pointers to instances and arrays are identical

array address is the address of the first element/ when you want to access so many element in the array, maybe cause segmentation fault

```c++
// difference between allocate array and pointer
// allocate array:
new typename [capacity]; 
// need capacity for the array
int *a_values{new int[capacity]{}}
delete[] a_values;
a_values = nullptr;
```

when allocate array, if initialize all the entries, it takes time and memory 

```c++
int *a_data{new(nothrow)int [capacity]};
// what does this mean? 
// It is possible to force new to simply return nullptr?
```

**Const**: a variable declared that cannot be reassigned

**Const local variable:** this means the parameter cannot be modified, usually after the initialization

**Const parameter:** This means the parameter cannot be modified, usually paired with pass-by-reference

**const after a member function declaration** : This means that no member variable can be modified. It means that this cannot be modified

ASCII table

**Wild pointer** are pointers that point to random addresses, usually becasue you have not initialized your variable

**Dangling pointers**: Dangling pointers are pointers pointing to deleted memory 

**Memory leak**: memory leak occurs when you have not freed all memory you  allocated by calling delete

**protecting pointer**: disallow changes to address held in pointer /  2 ways of changing pointers: changed variable or change address

**Pointer arithmetic**:

can using pointer arithmetic to looping through the array :   also can use ++ 

**a_ray[k]  == *(a_ray+k):** Access the kth entry of the array 

**&(a_ray[k]) == a_ray+k**: Find the address of kth entry beyond array 

pointer -difference type: **std::ptrdiaff_t** -----> this can return the difference between addresses

It is a type able to represent the result of any valid pointer subtraction operation. 

**Calculate the difference between addresses**

in array: address minus address can have the value

pointer difference return the value

**Recursive**: base case and recursive case

for the call stack, some compiler will simply reuse the memory already on the stack --> tail recursion

​       for the help session: two class for linked list 

dangling pointer and memory leak: one is pointer point to address that no longer allocated, one is heap memory has no pointer to pointed but still takes memory

std::size_t is a **unsigned int** can stores the maximum size of a theoretically possible object of any type (including array).

**template**:

```c++
// the template
template<class identifier> function declartion
// template determine can return any   
// example
template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}

int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetMax<int>(i,j);
  n=GetMax<long>(l,m); //  here when we want to use the function with template, specific it 
  cout << k << endl;
  cout << n << endl;
  return 0;
}

```



hello\0

insertion sort:

we have i and j, i iterate from 0 to size and j iterate from i to 0 to increase efficiency 

insertion sort and selection sort 



```c++
// insertion sort and selection sort
// insertion sort is like a card game . while selection sort is just keep swaping 

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
      // key is used to store the temp value of arr[i]
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
          // here we move j to right each time and it will just leave a hole 
        }  
        arr[j + 1] = key;  
    }  
}
// insertion sort in textbook
void insertion_sort(double array[], std::size_t const capacity)
{
  for (std::size_t k{1}; k< capacity; ++k){
    for (std::szie_t i{k}; i>0;i--){
      if(array[i-1]> array[i]){
        std::swap(array[i-1],array[i]);
      }else{
        break;
      }
    }
  }
}

// selection sort is find the minimum element in the unsorted array and exchanged with current element
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  {
          if (arr[j] < arr[min_idx])  
            min_idx = j;  
        }
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}
```

const means that this member function cannot assign to any member variable

**inheritance:**

use a base class and inheritance from --> are derived from the base class

Throwing exceptions:

instances of class can be thrown and caught as well

std::except is defined adn this class is virtual.

```c++
try{
	// Try some code
} catch(std::logic_error &e){
  std::cout  << e.what() << std::endl;
} catch(std::runtime_error&e){
  std::cout  << e.what() << std::endl;
} catch(std::exception &e){
  std::cout  << e.what() << std::endl;
  do something for *all* other exceptions
}
```

```c++
int f(int n){
	if(n==0){
		throw std::domain_error("division-by-zero-error")
	}
}
```

Polymorphism

override



Vector 3D:

The const after the function parameter list indicates that the fuction is not meant to change any member variables while the function is being called 

assignment operator--> '=' can assign every vector 

constrcutor: always pass the argument 

Encapsulation:

to prevent outsider to motify or change member variables, firstly, we need to set all the member variable private 

Private helper function 

this. access the member variables by a special local variable called this. This is a constant pointer that stores an address

**Memory management:**

using new TYPE or new TYPE[], delete , delete[] to request memory allocated in the heap

**Algorithm:** 

binary search:

Linear search:

bubble sort:

selection sort:

insertion sort:

class and Linked List:

```c++
class Node{
  public:
  Node(double value, Node *p_next);
  Node *get_next();
  double get_value();
  
  void set_next(Node *p_next_node);
  private:
  double value;
  Node *p_next;
}
Node *Node::get_next(){
  return this->p_next;
}
void set_next(Node *p_next_node){
  this->p_next = p_next_node;
}
// constructor for the node class
Node::Node(double value, Node *p_next){
  this->value = value;
  this->p_next = p_next;
}

// class for linked list using node
class Linked_list{
  public:
  	Linked_list();
    ~Linked_list();
    bool empty() const;
   	double front() const;
  	void push_front(double const new_value);
  	void pop_front();
  private:
  	Node *p_list_head_;
}
```

```c++
std::size_t linear_search(double const array[],
                         std::size_t const capacity,
                         double const sought_value);
// here it means under no circumstance will the array change 
```

pointer in class use -> instead of .

linked list head is a pointer to the first piece of data 

limitation of static memory:

the value stored in static can not go ou