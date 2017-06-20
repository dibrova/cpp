#include <iostream>
using namespace std;

int main()
{
	const int size = 10;
	int arr [size] ;//= {15, 35, 10, 5, 20, 1, 72, 69, 47, 51};
	
	cout << "Input " << size << " elements of array:" << endl;;
	for ( int i=0; i < size; i++)
	{
//		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	
	int minOdd = arr[0] , sumOdd = 0, sumEven = 0;
	for ( int i=size-1; i >= 0; i--)
	{
		cout << arr[i] << " ";
		
		if (arr[i]%2)
		sumOdd = sumOdd + arr[i];
		else
		sumEven = sumEven + arr[i];
		
		if ((minOdd > arr[i]) && (arr[i]%2 == 1))
		minOdd = arr[i];
		
	}
	
	for (int i = 0, f = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr[i] == arr[j])
				f++;
		}
			if (f)
			cout << "\nRep.digit: " << arr[i] << " ";
			f = 0;
	}
	cout << endl;
	cout << "sumOdd: " << sumOdd << endl;
	cout << "sumEven: " << sumEven << endl;
	cout << "minOdd: " << minOdd << endl;
}