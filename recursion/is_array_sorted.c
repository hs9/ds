/** Given an array check if the array is in sorted order using recursion
 */
#include <stdio.h>

unsigned char is_sorted(int *arr, unsigned int len)
{
	if (!arr) 
		return 0;

	if (len == 0 || len == 1)
		return 1; // sorted
	else {
		if (arr[1] >= arr[0]){
			printf("%d >= %d\n", arr[1], arr[0]); 
			return is_sorted(++arr, len-1);
		}
		else {
			printf("%d < %d\n", arr[1], arr[0]); 
			return 0;
		}
	}
}

int main()
{
	int arr[] = {4, 7, 7, 8, 10, 10, 6};
	unsigned int len = sizeof(arr) / sizeof(arr[0]);
	printf("%s\n", is_sorted(arr, len) ? "sorted" : "not sorted");	
}
