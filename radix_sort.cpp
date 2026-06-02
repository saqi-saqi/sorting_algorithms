#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
//Extracts the digit at the specified position (1-based index from the right)
int get_rem(int num, int pos)
{
    while (pos > 1) {
        num /= 10;
        pos--;
    }
    return num % 10;
}
//Radix Sort Implementation
void radix_sort(int arr[], int size) {
    std::vector<int> buckets[10]; 
    //Find the maximum number to determine the number of digits
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int maxDigits = 0;
    while (max > 0) {
        max /= 10;
        maxDigits++;
    }
    //Perform sorting for each digit
    for (int pos = 1; pos <= maxDigits; pos++) {
    //Distribute numbers into buckets based on the current digit
        for (int i = 0; i < size; i++) {
            int rem = get_rem(arr[i], pos);
            buckets[rem].push_back(arr[i]);
        }
    //insert numbers back into the Array
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int val : buckets[i]) {
                arr[index++] = val;
            }
            buckets[i].clear(); //Clear buckets for next iteration
        }
    }
}
//display Array
void display(int arr[], int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() 
{
    int array[] = {12, 340, 56, 78, 90, 131, 24, 35, 46, 789, 5436, 22, 89337};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Original array: ";
    display(array, size);
    radix_sort(array, size);
    cout << "Sorted array: ";
    display(array, size);
    return 0;
}
