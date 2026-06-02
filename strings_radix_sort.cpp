#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
//get the character at position(pos)
char get_char(const string& str, int pos)
{
    return (pos > str.length()) ? 'a' - 1 : str[str.length() - pos];
}
void radix_sort(vector<string>& arr)
{
    int maxLen = 0;
 //find the maximum length
    for (const string& str : arr) 
    if (str.length() > maxLen)
       maxLen = str.length();
    //checks all the strings character by character
    for (int pos = 1; pos <= maxLen; pos++) 
    {
        vector<string> buckets[27];
        //inserts strings into respective bucket
        for (const string& str : arr) 
        {
            char temp = get_char(str, pos);
            int bucketIndex = (temp == 'a' - 1) ? 0 : (temp - 'a' + 1);
            buckets[bucketIndex].push_back(str);
        }
        //rewrites strings into vector after every iteration
        int index = 0;
        for (int i = 0; i < 27; i++) 
        {
            for (const string& val : buckets[i]) arr[index++] = val;
            buckets[i].clear();
        }
    }
}
//displays vector
void display(const vector<string>& arr) 
{
    for (const string& str : arr)
    cout << str << " ";
    cout << endl;
}
int main() {
    vector<string> array = { "python", "java", "algorithm", "datastructure", "csharp", "cplusplus", "binary",
    "sorting", "recursion", "javascript", "assembly", "html", "sql" };
    cout << "Original array: ";
    display(array);
    radix_sort(array);
    cout << "Sorted array: ";
    display(array);
    return 0;
}
