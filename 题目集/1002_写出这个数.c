```
#include<stdio.h>
int main()
{
	int sum = 0;
	char c, *pinyin[] = {"ling", "yi", "er", "san", "si",
						 "wu", "liu", "qi", "ba","jiu"};
	
	while ((c = getchar()) != '\n')
		sum += c - '0';
		
	if(sum / 100)
		printf("%s ", pinyin[sum / 100]);
	if(sum / 10)
		printf("%s ", pinyin[sum / 10 % 10]);
	
	printf("%s", pinyin[sum % 10]);
	
	return 0;
}
```
