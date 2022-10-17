
#include <iostream>
using namespace std;

int binarySearch(int arr[], int min, int max, int element)
{
    if (max >= min)
    {
        int mid = min + (max - min) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] > element)
            return binarySearch(arr, min, mid - 1, element);
        return binarySearch(arr, mid + 1, max, element);
    }
    return -1;
}

int elementsearch(int arr[], int element)
{
    // defining min and max of array..
    int min = 0, max = 1;

    int value = arr[0];

    while (value < element)
    {
        min = max;
        max = max * 2;
        value = arr[max];
    }

    return binarySearch(arr, min, max, element);
}

int main()
{

    // let us take in the input value of array size
    int n;
    cin >> n;
    // taking sorted array input statically..

    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // let us take the input of the element to be found

    int element;
    cin >> element;

    // passing array and element to function without size of array...

    elementsearch(arr, element);

    int ans = elementsearch(arr, element);
    if (ans == -1)
        cout << "no such element exist ";
    else
        cout << "the index at which this element is present is : " << ans;
    return 0;
}
