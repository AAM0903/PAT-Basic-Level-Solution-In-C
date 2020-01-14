/*
让我们定义d?n?? 为：d?n?? =p?n+1?? ?p?n?? ，其中p?i?? 是第i个素数。
显然有d?1?? =1，且对于n>1有d?n?? 是偶数。“素数对猜想”认为“存在
无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20

输出样例:
4

*/
#include<stdio.h>
int main()
{
	int N;
	int i;
	int j;
	scanf("%d", &N);
	
	/* record primality of three successive numbers starting from 2, 3, 4 */
	int iPrimeMinus2 = 1, iPrimeMinus1 = 1, iPrime;
	int primes[100] = {2, 3};    /* Record the prime numbers before sqrt(10^5) */
	int twincount = 0;           /* Count of twin primes */
	int primecount = 2;          /* Count of prime numbers */
	
	/* Start from 4 */
	for (i = 4; i <= N; i++)
	{
		/* Test if i is a prime number */
		iPrime = 1;
		for(j = 0; iPrime && primes[j] * primes[j] <= i; j++)
			if(i % primes[j] == 0)
				iPrime = 0;
				
		/* If i is a prime number, record */
		if(iPrime)
		{
			if(primecount < 100)
				primes[primecount++] == i;
			if(iPrimeMinus2 == 1)
				twincount++;          /* A prime pair found */
		}
		
		/* Shift the primality flags to next number */
		iPrimeMinus2 = iPrimeMinus1;
		iPrimeMinus1 = iPrime;
	}
	printf("%d\n", twincount);	
	
	return 0;
} 
