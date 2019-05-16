/* Potenza, Matthew
 * cs 540 section 13481/13468
 * C++ program to iteratively calculate sine(x) using Taylor series
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX 10
const double PI = 4 * atan(1);

long long int fact(int n);
double convertdeg(double x);
double reducerad(double x);
double sinseries(double x);

int main (void)
{       
    char units = 'x';
    char answer = 'y';
    double x;

    cout << "This program will calculate sin(x) via Taylor series.\n";
    
    while (answer == 'Y' || answer == 'y') {        
              
        while (units != 'd' && units != 'D' && units != 'r' && units != 'R') {
            cout << "Enter d or r for x in degrees or radians: ";
            cin >> units;
            while ((getchar()) != '\n');    /* clear input buffer */
        }
        
        cout << "Enter x: ";
        cin >> x;                           /* FIXME: error if char entered */
        
        if (units == 'D' || units == 'd') { 
            x = convertdeg(x);              /* convert deg to rad */
            cout << "x in radians: " << x << endl;
        }
        if (x > PI) {
            x = reducerad(x);               /* truncate large numbers */
            cout << "x % PI value: " << x << endl; 
        }

        cout << "sinseries(): " << sinseries(x) << endl;
        cout << "cmath sin(): " << sin(x) << endl;

        units = 'x';                        /* reset units value */
        cout << "Continue (Y/N)? ";
        cin >> answer;
        while ((getchar()) != '\n');        /* clear input buffer */
            
    }

    system("pause");
    return 0;
}

long long int fact(int n)                   /* calculates factorial of n */
{
    if (n > 1)
        return n * fact(n - 1);
    else
        return 1;
}

double sinseries(double x)                  /* calculates sin(x) iteratively */
{
    int n = 1;        
    double sine = 0.0;
    double term = 1.0;
        
    if (x == 0 || fmod(x, PI) == 0)         /* return 0 if x is mult of Pi */
        return 0;
        
    while (n <= MAX && term >= 0.0001) {
        term = (pow(x, (n * 2) - 1)/fact((n * 2) - 1));
        sine -= term * pow(-1, n);
        n++; 
    }
    return sine;
}

double convertdeg(double d)                 /* converts degrees to radians */
{               
    return d * PI / 180; 
}

double reducerad(double x)                  /* reduces radians if > PI */
{                                           /* prevents overflow caused by */
    return (fmod(x, PI));                   /* calc factorial and powers */
}                                           /* of uneccesarily large numbers */






