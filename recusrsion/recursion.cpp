#include <iostream>
using namespace std;

// What's Recursion Function ? a Function that calls itself on a recursive Structure.
// What's Recursive Structure ? a Structure defined in terms of Itself
// ... has sub-instances of itself AND at least a base Instance

/**
 * List Structure
 *  either Empty []
 *  or element::List
 *  
 * Power(base, exp) Function
 *  either 1    if exp = 0
 *  or  base * Power(base, exp - 1)
 * 
 * Factorial(n) Function
 *  either 1    if n = 0
 *  or n*Factorial(n-1) otherwise
 */

int power(int base, int exp){
    if(exp == 0){   // base case
        return 1;
    }else{
        // look the problem are reduced! so it progress to the base case
        return base * power(base, exp-1);
    }
}
int pow(int base, int exp){
    if (base < 0){
        return power(base, exp);
    }else{
        return 1/power(base, exp);
    }
}
 
int fact(int n){
    if (n == 0){
        return 1;   // base case
    }else{
        return n *  fact(n-1);
    }
}






int pow(int base, int exp){
    if(exp == 0){
        return 1;
    }else{
        return base * pow(base, exp-1);
    }
}





int fact(int n){
    if (n == 0){
        return 1;
    }else{
        return n * fact(n-1);
    }
    
}



















int main(){
    cout << "Factorial of 5 is: " << fact(5) <<endl;
    cout << "power of base 5 to power 2 is : " << pow(5, 2) <<endl;
    return 0;
}