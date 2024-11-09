//REPRESENTING A POLYNOMIAL USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
	int exp;
	int val;
	struct poly *next;
} poly;
void create(poly **);
void display(poly *);
int main()
{
	poly *p1 = NULL;
	int ch;
	printf("\nPolynomial-1:-\n");
	create(&p1);
	display(p1);
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
        while (t != NULL) {
            if (t->exp == p->exp) {
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
