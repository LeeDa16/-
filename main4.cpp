#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node 
{
	char date[20];
	char name[20];
	int num;
	struct Node *prior;
	struct Node *next;
};
struct Node *CreateList(int n);

int ListSize(struct Node *head);

int datecmp(const char *s1, const char *s2);

int scmp(const struct Node& a, const struct Node& b, char rl)
{
	switch(rl)
	{
	case 'L':
		return -datecmp(a.date, b.date);
	case 'l':
		return datecmp(a.date, b.date);
	case 'T':
		return -strcmp(a.name, b.name);
	case 't':
		return strcmp(a.name, b.name);
	case 'V':
		return(b.num - a.num);
	case 'v':
		return(a.num - b.num);
	default:
		break;
	}
	return 0;
}

int compare(struct Node *p, struct Node *q, char *s, int len)
{
	int res[3], i;
	for(i = 0;i < len;i++)
	{
		res[i] = scmp(*p, *q, s[i]);
	}
	for(i = len;i < 3;i++)
	{
		res[i] = 0;
	}
	return res[0] > 0 || (res[0] == 0 && res[1] > 0) || (res[0] == 0 && res[1] == 0 && res[2] == 1);
}

struct Node *DeleteList(struct Node *head, int n, int m);

struct Node *SortList(char *s1, struct Node *head);

void PrintList(struct Node *head);

int main()
{
	struct Node *list;
	int n, m, i, a, b;
	char c, s[5];
	scanf("%d", &n);
	list = CreateList(n);
	scanf("%d", &m);
	for(i = 0;i < m;i++)
	{
		getchar();
		scanf("%c", &c);
		if(c == 'D')
		{
			scanf("%d", &a);
			scanf("%d", &b);
			list = DeleteList(list, a, b);
		}
		else
		{
			scanf("%s", s);
			list = SortList(s, list);
		}
	}
	PrintList(list);
	return 0;
}

struct Node *CreateList(int n)
{
	int i;
	struct Node *head, *p, *q;
	head = p = q = NULL;
	for(i = 0;i < n;i++)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		scanf("%s", &p->date);
		scanf("%s", &p->name);
		scanf("%d", &p->num);
		if(head == NULL)
		{
			head = p;
			head->prior = NULL;
			q = p;
		}
		else
		{
			p->prior = q;
			q->next = p;
			q = p;
		}
	}
	if(q != NULL)
		q->next = NULL;
	return head;
}

int ListSize(struct Node *head)
{
	int size = 0;
	struct Node *p = head;
	while (p)
	{
		size++;
		p = p->next;
	}
	return size;
}

struct Node *DeleteList(struct Node *head, int n, int m)
{
	struct Node *p, *q, *r, *s;
	p = q = head;
	r = s = NULL;
	int i;
	for(i = 0;i < m - 1;i++)
	{
		if(i < n - 1)
			p = p->next;
		q = q->next;
	}
	if(p == head)
	{
		head = q->next;
		head->prior = NULL;
	}
	else
	{
		r = p->prior;
		s = q->next;
		r->next = s;
		if(s)
			s->prior = r;
	}
	free(p);
	return head;
}

int datecmp(const char *s1, const char *s2)
{
	int i, len = strlen(s1);
	for (i = 0; i < len; i++)
	{
		if(s1[i] > s2[i])
			return 1;
		if(s1[i] < s2[i])
			return -1;
	}
	return 0;
}

struct Node *SortList(char *s1, struct Node *head)
{
	struct Node *p, *q, *r, *s;
	int len, size, i, j;
	len = strlen(s1);
	size = ListSize(head);
	for(i = 0;i < size - 1;i++)
	{
		p = head;
		q = p->next;
		if(compare(p, q, s1, len))
		{
			r = q->next;
			q->prior = NULL;
			q->next = p;
			p->prior = q;
			p->next = r;
			if(r)
				r->prior = p;
			head = q;
		}
		else
			p = p->next;
		for(j = 1;j < size - i - 1;j++)
		{
			q = p->next;
			if(compare(p, q, s1, len))
			{
				r = q->next;
				s = p->prior;

				s->next = q;
				q->prior = s;
				q->next = p;
				p->prior = q;
				p->next = r;
				if(r)
					r->prior = p;
			}
			else
				p = p->next; 
		}
	}
	return head;
}

void PrintList(struct Node *head)
{
	struct Node *p = head;
	while(p)
	{
		printf("%s %s %d\n", p->date, p->name, p->num);
		p = p->next;
	}
}
