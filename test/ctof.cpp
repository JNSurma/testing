#include <iostream>
using namespace std;

int main(){
double c, f;

while(1){
	cout << "Enter Celcius(q to quit): ";
	cin >> c;
	if (cin.fail()) break;
	cin.clear();
	f = c * 9/5 +32;
	cout << c << " is " << int(f) << endl;
}
return 0;
}
