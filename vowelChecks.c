/*WAP to check whether the given char is vowel or consonant

	eg:
		Enter a char : a
		Vowel

	eg:
		Enter a char : p
		Consonant
*/
#include<stdio.h>
main(){
	char chr; 
	printf("Enter a character : ");
	scanf("%c", &chr);
	if((chr>='A' && chr<='Z') || (chr>='a' && chr<='z')){
		switch(chr)
		{
			case'A':
			case'E':
			case'I':
			case'O':
			case'U':
			case'a':
			case'e':
			case'i':
			case'o':
			case'u':
				printf("This is a vowel: %c", chr);
				break;
			default:
			printf("This is a constant: %c", chr);
		}
	}
}