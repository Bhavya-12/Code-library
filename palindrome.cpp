#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(char *str) {
   int n = strlen(str);
   if (n == 1) {
      return true;
   }
   int start = 0, end = n - 1;
   while (start < end) {
      if (str[start] != str[end]) {
         return false;
      }
      ++start;
      --end;
   }
   return true;
}
int requiredAppends(char *str) {
   if (isPalindrome(str)) {
      return 0;
   }
   return 1 + requiredAppends(str + 1);
}
int main() {
   char str[1000]; 
   cin>>str; 
   cout << "Characters to be appended = " << requiredAppends(str) << endl;
   return 0;
}