//ADDITION OF  POLYNOMIALS
#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
	int exp;
	int val;
	struct poly *next;
} poly;
void create(poly **);
poly *add(poly *, poly *);
void display(poly *);
int main()
{
	poly *p1 = NULL, *p2 = NULL, *p3 = NULL;
	int ch;
	printf("\nPolynomial-1:-\n");
	create(&p1);
	printf("\nPolynomial-2:\n");
	create(&p2);
	printf("\nPolynomial-1:-\n");
	display(p1);
	printf("\nPolynomial-2:\n");
	display(p2);
	p3 = add(p1, p2);
	printf("\nPolynomial-3:\n");
	display(p3);
	return 0;
}
void create(poly **l)
{
    poly *t= NULL;
	poly *r = *l;
	int ch = 1;
	poly *p = NULL;
	printf("\nEnter the data to create a polynomial:-\n\n");
	while (ch)
	{
		p = (poly *)malloc(sizeof(poly));
		if (p == NULL)
		{
			printf("Memory allocation failed\n");
			return;
		}
		else
		{
			printf("Enter value: ");
			scanf("%d", &(p->val));
			printf("Enter exponent: ");
			scanf("%d", &(p->exp));
            p->next = NULL;
            t = *l;
            while (t != NULL) 
			{
                if (t->exp == p->exp) 
				{
                   t->val += p->val;
                   free(p); 
                   break;
                }
                t = t->next;
            }
            if (*l == NULL)
				*l = p;
			else
				(r)->next = p;
			    r = p;
        }
		printf("\nPress 0 to stop and 1 to continue: ");
		scanf("%d", &ch);
		}
		printf("\nPolynomial created!\n");
	}

void display(poly *l)
{
	if (l == NULL)
		printf("Polynomial is empty!\n");
	else
	{
		while (l->next != NULL)
		{
			if (l->exp == 0)
				printf("%d + ", l->val);
			else if (l->exp == 1)
				printf("%dx + ", l->val);
			else
				printf("%dx^%d + ", l->val, l->exp);
			l = l->next;
		}
		if (l->exp == 0)
			printf("%d\n", l->val);
		else if (l->exp == 1)
			printf("%dx\n", l->val);
		else
			printf("%dx^%d\n", l->val, l->exp);
		l = l->next;
	}
}

poly *add(poly *p1, poly *p2)
{
	poly *t1 = p1, *t2 = p2, *t3 = NULL, *p3 = NULL, *p = NULL, *l = NULL;

	while (t1!= NULL)
	{
		t2 = p2;
		while (t2 != NULL && t2->exp != t1->exp)
			t2 = t2->next;
		p = (poly *)malloc(sizeof(poly));
		p->exp = t1->exp;
		p->val = t1->val;
		p->next = NULL;
		if (t2 != NULL && t2->exp == p->exp)
			p->val += t2->val;
		if (p3 != NULL)
			p3->next = p;
		else
			l = p;
		p3 = p;
		t1 = t1->next;
	}
	t2 = p2;
	while (t2 != NULL)
	{
		t3 = l;
		while (t3 != NULL && t3->exp != t2->exp)
			t3 = t3->next;
		if (t3 == NULL)
		{
			p = (poly *)malloc(sizeof(poly));
			p->exp = t2->exp;
			p->val = t2->val;
			p->next = NULL;
			if (p3 != NULL)
				p3->next = p;
			else
				l = p;
			p3 = p;
		}
		t2 = t2->next;
	}
	return l;
}