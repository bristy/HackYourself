//http://www.geeksforgeeks.org/reverse-a-string-using-recursion/
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

void reverseStr(char *str, int l, int r){
		if(l<r){
			int temp = str[l];
			//printf("%c\n", str[r]);
			str[l] =  str[r];
			str[r] = temp;
			
			reverseStr(str, l+1, r-1);
		}
}
int main() {
	char str[] = "brajesh";
	
	printf("before reverse: %s\n", str);
	reverseStr(str, 0, strlen(str)-1);
	printf("after reverse: %s", str);
	return 0;
}
