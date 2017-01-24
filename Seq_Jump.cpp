#include <iostream>
using namespace std;

int SequentialSearch (int array[], int key, int start, int end);
int JumpSearch(int array[], int size, int key);


int SequentialSearch (int array[], int key, int start, int end)
{
	for(start; start < end; start++)
	{
		cout << start << endl;
		if(array[start] == key)
		{
			return start;
		}
	}
	
	return 123;
}


int JumpSearch(int array[], int size, int key)
{
	cout << "JUMPStarted" << endl;
	int m = 3;
	int i = 0;
	int location = -1;
	
	for(i; i < size; i = i + m)
	{
		cout << i << endl;
		
		if(array[i] == key)
			return i;
			
		if(array[i] > key)
		{
			location = SequentialSearch(array, key, i-m+1, size);
			break;
		}
	}
	
	if(location == -1 && i < size)
		location = SequentialSearch(array, key, i-m, i);
	
	return location;
}

int main()
{
	int A[] = {1,3,5,7,9,22,44,55,77,88,99,123,345,567,789,12345,43567,56788};
	cout << " hehehe    ";
	cout << JumpSearch(A, 18, 99);
}
