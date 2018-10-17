#include	<stdio.h>
#include	<stdlib.h>
#define		MAX 	10


typedef	struct _node
{
	int		id;
	int		data;
	struct _node 	*next;
} NODE;


NODE	*head = NULL;
NODE	*tail = NULL;
int		size=0;


int	append(int id, int data)
{
	NODE	*p;
	p = (NODE *)malloc(sizeof(NODE));
	p->id = id;
	p->data = data;
	p->next = NULL;

	if ( head == NULL)
		head = p;
	if ( tail == NULL)
		tail = p;
	else
	{
		tail->next = p;
		tail = p;
	}
	size++;
	return size;
}

NODE	*get_head(void)
{
	return head;
}
void	clean_all()
{
	free(head);
	free(tail);
}
int	main()
{
	NODE	*h, *p;

	append(98, 100);
	append(99, 101);

	h = get_head();
	p = h;
	while ( p != NULL)
	{
		printf ("Node id : %d, data: %d", p->id, p->data);
		p = p->next;
	}
	clean_all();

}
