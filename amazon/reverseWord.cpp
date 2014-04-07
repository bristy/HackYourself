
// =====================================================================================
//
//       Filename:  reverseWord.cpp
//
//    Description:  reverse the words of a givin string
//    input: "i like you"
//    output: "you like i"
//
//        Version:  1.0
//        Created:  Monday 07 April 2014 10:07:48  IST
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Brajesh Kumar (), kbrajesh176@gmail.com
//   Organization:  
//
// =====================================================================================
#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define EXIT_SUCCESS 0


// ===  FUNCTION  ======================================================================
//         Name:  reverse
//  Description:  
// =====================================================================================
	void
reverse ( char *start, char *end )
{
	int temp;
	while(start < end){
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
	return ;
}		// -----  end of function reverse  -----

// ===  FUNCTION  ======================================================================
//         Name:  reverseWord
//  Description:  
// =====================================================================================
	void
reverseWord ( char *str )
{
	// reverse all words
	char *beginWord = str;
	char *endWord = str;
	while(*endWord){
		endWord++;
		if(*endWord == '\0'){
			reverse(beginWord, endWord-1);
		}else if(*endWord == ' '){
			reverse(beginWord, endWord-1);
			beginWord = endWord+1;	
		}
	}
	reverse(str, endWord-1);
	return ;
}		// -----  end of function reverseWord  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  
// =====================================================================================
	int
main ( int argc, char *argv[] )
{
	char str[] = "I like You";
	printf("before reverse: %s\n", str);
	reverseWord(str);
	printf("after reverse: %s\n", str);
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
