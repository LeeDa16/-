#include <stdio.h>
int main()
{
	long long int min, max, i, n, min1, max1;
	int flag = 0;
	scanf("%lld", &min);
	scanf("%lld", &max);
	for(i = 1;;i++)
	{
		if(i * i * i >= min && flag == 0)
		{
			min1 = i;
			flag = 1;
		}
		if(i * i * i == max)
		{
			max1 = i + 1;
			break;
		}
		if(i * i * i > max)
		{
			max1 = i;
			break;
		}

	}
	printf("%d", max1 - min1);
}

