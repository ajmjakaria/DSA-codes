#include<bits/stdc++.h>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int target, int n)
{
	int low = 0, high = n;  // Initialize low and high pointers
	while(low <= high)
	{
		int mid = (low + high) / 2;  // Calculate mid index
		if(arr[mid] == target)  // If the middle element is the target
			return mid;  // Return the index of the target
		else if (arr[mid] > target)  // If middle element is greater than the target
			high = mid - 1;  // Adjust the high pointer to search in the left half
		else if (arr[mid] < target)  // If middle element is less than the target
			low = mid + 1;  // Adjust the low pointer to search in the right half
	}
	return -1;  // Return -1 if the target is not found
}

int main()
{
    int n, target;
    
    // Input the number of elements in the array
    scanf("%d", &n);
    int arr[n];
    
    // Input elements of the array
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // Input the target element to search for
    cin >> target;

    // Sort the array in ascending order (required for binary search)
    sort(arr, arr + n);
    
    // Display the sorted array
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    cout << endl;

    // Call binary search function to find the target element in the array
    int idx = binarySearch(arr, target, n);

    // Check if target is found and display the result
    if(idx >= 0)
        printf("%d is at index %d\n", target, idx);
    else
        printf("Not Found!\n");
 
    return 0;
}

/* Sample I/O
5
4 5 1 2 7
5
*/
