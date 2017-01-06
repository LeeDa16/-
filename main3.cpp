#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *move(char *s, int n, int step);
int main()
{
	int n, m, i, j, k, p, q;
	char s1[20], s2[20], s3[20], s4[20], s5[20][20], c;
	scanf("%d", &n);
	scanf("%d", &m);
	getchar();
	gets(s1);
	gets(s2);
	for(i = 0;i < m;i++)
	{
		scanf("%c", &c);
		scanf("%d", &p);
		scanf("%d", &q);
		getchar();
		gets(s3);
		j = 0;
		strcpy(s4, move(s2, n, p));
		while(s3[j] != '\0')
		{
			if(c == 'E')
			{
				for(k = 0;k < n;k++)
				{
					if(s3[j] == s1[k])
					{
						s5[i][j] = s4[k];
						break;
					}
				}
			}
			else
			{
				for(k = 0;k < n;k++)
				{
					if(s3[j] == s4[k])
					{
						s5[i][j] = s1[k];
						break;
					}
				}
			}
			strcpy(s4, move(s4, n, q));
			j++;
		}
		s5[i][j] = '\0';
	}
	for(i = 0;i < m;i++)
	{
		printf("%s\n", s5[i]);
	}
	return 0;
}
char *move(char *s, int n, int step)
{
	int len, i;
	len = strlen(s);
	char *s1;
	s1 = (char *)malloc((len + 1) * sizeof(char));
	for(i = 0;i < n;i++)
	{
		s1[i] = s[(i + step) % n];
	}
	s1[i] = '\0';
	return s1;
}