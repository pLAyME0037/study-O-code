// C++ program to illustrate the fesetround 
#include <cfenv> 
#include <iostream> 
using namespace std; 
int main() 
{ 
	// Save the current floating-point environment 
	fenv_t current_environment; 
	fegetenv(¤t_environment); 
	
	// Set the rounding mode to round towards zero 
	fesetround(FE_TOWARDZERO); 
	
	// Perform some floating-point operations 
	double result = 10.5 / 3.0; 
	cout << "Result (round toward zero): " << result 
		<< endl; 

	return 0; 
}
