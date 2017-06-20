#include <iostream>
using namespace std;

//void main()
int main()
{
	int a; 
	int b;
	for (a=0; a<=10;a++)
	{
		for (b=0; b<=10 ;b++)
		{
			if (//a==b || 
//			a==0 || b==0 || 
//			a==10 || b==10 ||
//			     a+b==10 ||
//			     a+b<=10 ||
//			   b == 10/2 + a || b == 10/2 - a || a == 10/2  ||
			   a == 10/2 + b || a == 10/2 - b || b == 10/2  + a || b == 10/2 - a + 10 ||
			   a <= 10/2 && a + b >= 5// || a <= 10/2 && a+b -10 <= 5
			   ) 
			{
		 	cout << a << ":" << b << "\t";;
//			cout << " @";
			}
				else
			{
					cout << "  \t";
			}
		}
    cout << endl << endl;
	}
	
}