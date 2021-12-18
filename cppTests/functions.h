#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <typeinfo>
#include <exception>
#include <algorithm>
//class Base { virtual void f(){} }; // TypeID is different
//class Derived : public Base {};    //  if these are used
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_LIMIT 100
#define MIN_LIMIT 0

class T{
public:
    T(){    //Constructor
        name = "Wally Willace";
    }
    ~T(){   //Destructor
        std::cout << "Killing Sir William Wallace" << std::endl;
    }
    void setName(std::string x){
        name = x;
    }
    std::string getName(){
        return name;
    }
private:
    std::string name;
};

void classAccess(){
    //Class Constructor/Destructor Private var access
    T t;    //Constructor Called Here
    std::cout << "Before t.setName: " << t.getName() << "\n";
    t.setName("Sir William Wallace");
    std::cout << "After t.setName: " << t.getName() << "\n";
    std::cout << "Goodbye cruel world!\n";
}

void throwErr(){
//Throwing errors
    int x = 1;
    int number;
    int largest = 0;
    int total = 0;

    std::cout << "Enter 5 numbers between 0 and 100: ";
    while(x <=5){
        std::cin >> number;
    if(std::cin.fail()){
        throw std::range_error("Value out of range. Non-numeric.");
    }
    if(number > MAX_LIMIT){
        throw std::range_error("Value out of range. Too high.");
    }
    else if(number < MIN_LIMIT){
        throw std::range_error("Value out of range. Too low.");
    }
        largest = MAX(largest, number);
        total += number;
        x++;
    }

    std::cout << "Your total is: " << total << "\n";
    std::cout << "Largest number entered was: " << largest << "\n";
}

int strComp(){
//String compare
    int authentication = 0;
    std::string cUsername;
    std::string cPassword;

    std::cout << "Username: ";
    std::cin >> cUsername;
    std::cout << "Pass: ";
    std::cin >> cPassword;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //Clear input buffer before std::getline() See: https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer

    if( cUsername.compare("admin") == 0 && cPassword.compare("pass") == 0 ){
        authentication = 1;
    }
/*
    if( authentication ){
         std::cout << "Access granted\n";
    }
    else{
        std::cout << "Wrong username and password\n";
    }
*/
    //Conditional (or Ternary) Operator (?:) equivalent to above code.
    (authentication ? std::cout << "Access Granted!\n" : std::cout << "Access Denied!\n");

return authentication;
}

std::string cinIgnore(int auth){
    std::string fullName;
    if (auth){
//        std::cin.clear();
        std::cout << "What is your name? ";
//      std::getline(std::cin >> std::ws, fullName);  //Other way that works, I think cin.ignore() is better?
        std::getline(std::cin, fullName);
        std::cout << "Hello " << fullName << ", nice to meet you!\n";
    }
return fullName;
}

void typeID(){
    class Base { virtual void f(){} };
    class Derived : public Base {};
//Type ID See https://www.cplusplus.com/doc/tutorial/typecasting/
    try {
        Base* a = new Base;
        Base* b = new Derived;
        std::cout << "a is: " << typeid(a).name() << '\n';
        std::cout << "b is: " << typeid(b).name() << '\n';
        std::cout << "*a is: " << typeid(*a).name() << '\n';
        std::cout << "*b is: " << typeid(*b).name() << '\n';
    } catch (std::exception& e) { std::cout << "Exception: " << e.what() << '\n'; }
}

void numericLimits(){
        //Numeric Limits modified from <https://en.cppreference.com/w/cpp/types/numeric_limits>
        //Using Box Drawing Unicode Characters
        std::cout
        << "\u256D";
        for(int i=0; i < 63; i++){std::cout << "\u2500";}
        std::cout << "\u256E\n"
        << "│ type\t\t│ lowest()\t│ min()\t\t│ max()\t\t│\n"
        << "│ bool\t\t│ "
        << std::numeric_limits<bool>::lowest() << "\t\t│ "
        << std::numeric_limits<bool>::min() << "\t\t│ "
        << std::numeric_limits<bool>::max() << "\t\t│\n"
        << "│ " << "uchar\t\t│ "
        //The + operator converts the unsigned char to an int through integer promotion.
        << +std::numeric_limits<unsigned char>::lowest() << "\t\t│ "
        << +std::numeric_limits<unsigned char>::min() << "\t\t│ "
        << +std::numeric_limits<unsigned char>::max() << "\t\t│\n"
        << "│ " << "int\t\t│ "
        << std::numeric_limits<int>::lowest() << "\t│ "
        << std::numeric_limits<int>::min() << "\t│ "
        << std::numeric_limits<int>::max() << "\t│\n"
        << "│ " << "float\t\t│ "
        << std::numeric_limits<float>::lowest() << "\t│ "
        << std::numeric_limits<float>::min() << "\t│ "
        << std::numeric_limits<float>::max() << "\t│\n"
        << "│ " << "double\t│ "
        << std::numeric_limits<double>::lowest() << "\t│ "
        << std::numeric_limits<double>::min() << "\t│ "
        << std::numeric_limits<double>::max() << "\t│\n"
        << "\u2570";
        for(int i=0; i < 63; i++){std::cout << "\u2500";}
        std::cout << "\u256F\n";
}

void writeFile(std::string name){
// https://www.cplusplus.com/doc/tutorial/files/
// see also https://stackoverflow.com/questions/2718779/correct-exceptions-in-c  for other stuff
// Don't think errors are working
    std::string fileName = "myfile.txt";
    std::string quest;
	std::ofstream myWriteFile;
	myWriteFile.open(fileName, std::ios::app);

	if(myWriteFile.is_open()){
        reverse(name.begin(),name.end());
//        std::cin.clear();
	    std::cout << "What is your quest? ";
        std::getline(std::cin, quest);
        reverse(quest.begin(),quest.end());
	    myWriteFile << quest << " ," << name << std::endl;
		myWriteFile.close();
	}
	else{
        std::cerr << "Error opening file for writing\n";
	}

	std::string line;
	std::ifstream myReadFile("myfile.txt");

	if (myReadFile.is_open()){
		while (std::getline(myReadFile, line)){
			std::cout << line << '\n';
		}
		myReadFile.close();
	}
	else{
		std::cerr << "Error opening file for reading.\n";
	}
}

#endif // FUNCTIONS_H_INCLUDED
