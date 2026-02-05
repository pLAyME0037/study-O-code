// C++ program to illustrate the fesetexceptflag() 
#include <cfenv> 
#include <iostream> 
using namespace std; 
int main() 
{ 
	fexcept_t exception_flags; 
	fesetexceptflag(&exception_flags, FE_ALL_EXCEPT); 

	// Division by zero 
	double result = 1.0 / 0.0; 
	cout << "Result: " << result << endl; 

	int Flags_encountered = fetestexcept(FE_ALL_EXCEPT); 
	if (Flags_encountered & FE_DIVBYZERO) { 
		cout << "Division by zero exception occurred!"
			<< endl; 
	} 
	if (Flags_encountered & FE_OVERFLOW) { 
		cout << "Overflow exception occurred!" << endl; 
	} 

	return 0; 
}
