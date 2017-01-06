#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, c, d, e, i;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int *s = (int *)malloc(e * sizeof(int));
	int *l = (int *)malloc(e * sizeof(int));
	int *born = (int *)malloc(e * sizeof(int));
	s[0] = born[0] = a;
	l[0] = 0;
	for(i = 1;i < e;i++)
	{
		born[i] = l[i - 1];
		s[i] = born[i] + s[i - 1];
		if(i >= b)
		{
			l[i] = l[i - 1] + born[i - b];
			s[i] -= s[i - b];
		}
		else l[i] = 0;
		if(i >= d + c)
			l[i] -= born[i - d - c];
	}
	printf("%d", s[i - 1] + l[i - 1]);
	return 0;
}
