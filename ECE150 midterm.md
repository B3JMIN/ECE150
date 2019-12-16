questions:   :question:

gcd and another one!

gcd and lcm, lcm = a*b / gcd(a,b)

flow chart and regex

mean and median questions

while (){} what does this mean? continue run until the 

bitwise operators:

bitwise three main operators:

& AND with two binary numbers, it only return 1 if two of the numbers are all 1

| OR with two binary numbers, it return 1 of one of the two is 1 (This can be both) :fire:

^ XOR exclusivse or, it only return 1 if only one of two but not both of them is 1 

~ NOT not, basically, it will reverse every bit of the initial binary number.

Bit shift operators:

//  > >   this can mean shift right, multiply in binary numbers

//  <<    this can mean shift left, divide in binary numbers









prefix operator and postfix operator

++x increments x and produces(as the expression's result) x as an value 

x++ increments ax and produce(as the expression's result) the original value of x

example:

int a = 1;

int b = -3;

int c = 2;

b = a++;   // b doesnt change since it is post increment, b=-3 and a = 2 now 

c += ++a; // c = 2 + a + 1, and a is 2, so c = 5 and since a +1 here, so a = 3

cout << a <<""<< b << ""<< c;

3 1 5 

The valid range of char and unsigned char:

char: -128 to 127 (remember that when you count the corresponding value of negative signed, you need to do 2's complement and you need to add 1)

0 is part of the postive integer. so positive integer number is same as negative integer number.

bitwise and shift operation

**review of notes:**

scientific representation:

+(-) n * 10 ^ b 

mantissa and base is 10 (in real computer it is 2 ) and exponent

The total number of digits are precision. maximum precision: float is 7 and double is 16.

some weakness of scientific presentation: loss of some precision such as x+y = x?

**floating points:**

for unsigned, we always do addition and mutiplication.

take 1 byte as an example: the largest number is 255 and the lowest number is 0 

some time you can find that 65535 + 1 = 0

call stack : compiler will reserve bytes for parameters and then additional local variables

sizeof can determine the size of a type of data

upcasting of unsigned and signed binary numbers:

for unsigned: just give all the begining numbers to be 0;

for negative signed, you need to set all the additional bits to 1

***lost carry*** : when the result produced something than larger than the memory can store, that is called a lost carry.



**binary and hexdecimal**:

binary begins with 0b and it only has 0 and 1 

binary to decimal, just do 2 exponentional; decimal to binary, just do % and write down the modulos from down to beginning until the quotient is 0 

remember the look at table of hexdecimal to binary:

![img](https://lh5.googleusercontent.com/-gIIq481Fmyn3aligdX-sAZXra9hrZkzMojsskZs4qbHRxMC0aYjJ1F1zU3WL2W83TVz62CGcto-orNUiD3yZU5KDkKr2mqHSUFXN2TAHEd1E_DKDPtV6-lr4xygt3KumVcyJe4V4-M)

everytime you just need to write down the binary numbers, divide with 1 byte for each, add more 0 in front, and translate with this table.

hexdecimal start with 0x: and it has 0-9 and a to f(AtoF)

**The break statement**

break the most inner **<u>*loop*</u>**, which means that if else is not  a loop!!!

go to statement will not be on the exam?



**while, for and do while**

the for loop statement: for(initialization, conditional, incremental statement)

for here, the k++ and ++k doesnt matter since it is already the end of loop

some examples can be **fibonacci and factorial and check of prime numbers.**

The main difference between while and do while is that: do while execute at least once.

*collatz conjecutre* problem is actually a counter problem:

and we can print the first  100 numbers, just set a while loop for 100 

check for prime numbers: use long division 

**binomial coefficient**

**greatest common denominator**:![image-20191020142803641](/Users/Benjamin/Library/Application Support/typora-user-images/image-20191020142803641.png)

another algorithm is :

1. if m = n  gcd(m,n) = m;

2. if m > n gcd(m,n) = gcd(m-n, n)
3. otherwise, gcd(m,n) = gcd(m, n-m)

check until the remiander is 0

notes: there is no need to have a else after the while loop, we can just return after the loop, that means an escape.

**factorials:** can use recursive or while.

[**Find the interger square root of an integer**:](https://en.wikipedia.org/wiki/Integer_square_root)

and we do have find x = cos(x)

**if else statement**

almost same

console input: have an identifier before you call cin 

how to cin a string

 <img src="/Users/Benjamin/Library/Application Support/typora-user-images/image-20191020145033705.png" alt="image-20191020145033705" style="zoom:50%;" />

**The call stack**

first parameter and then local variables, then the inner functions with its parameters and local variables

return value from top to bottom put on the top of the stack 

if it is assigned through variables, it will not be changed in stack?



**Local variables**

scope of the local variables

when you swipe two local variables, you want to have  a temp variable

automatic assignment operators 



**Basic knowledges:**

literal data, identifiers, arthemetic operators, console output, functions, conditional statement and comparison statement and conditional statement.





**How to draw flow chart** 



**regex**

for describing characters,we can use [a-z] or [0-9] etc

[0-9] means there must be a digit from 0-9

[0-9]* means there are zero or more digits from 0-9

[+-]? there is optionally a + or -

for the number of digit: we can have {} to represent.

canadian phone number:

(\+1-)? [0-9]{3}-[0-9]{3}-[0-9]{4}

**identifiers**

some identifiers: int main std cout endl return 

any comb of underscores, letter and numbers where first character is not a number can be used as identifier (case sensetive)

regex for identifiers

[_A-Za-z][_A-Za-z0-9]* 



**data unit conversions**

byte = 8 bits

kilobyte = 1024 bytes

megabyte = 1024 kilobytes

gigabyte = 1024 megabytes

terabyte = 1024 gigabytes

**cmath libary**

sqrt()



for the **root finding problem**, the algorithm of problem solving is set lowest bound and upper bound, let x firstly be lowest, check the value of y, fabs() in cmath library. if the fabs(y ) < best_y, which is 1e6, return x, else, increment x with set_interval.



set a contine_program bool for exit and continue the program and it can be return at the end of program.

ASCII table means that we can just increment character with integers so it can change according to ASCII table. Notes that if the value less than a (A) or larger than z(Z), we will add or subtract 26 to make it back 



Escape sequence:

an escape character indicate that the next character is interpreted.





