#include <strings.h>

#define SIZE 64
typedef int data_t; 

typedef struct {
	data_t list[SIZE];
	int last;
}seqlist;

seqlist * createSeqlist()
{
	seqlist *seq = (seqlist *)malloc(sizeof(seqlist));
	if(NULL == seq)
		return NULL;

	bzero(seq -> last, sizeof(seq->list));
	seq->last = -1;

	return seq;
}

int seqlist_is_empty(seqlist *seq)
{
	if(NULL != seq)
		return ((seq->last == -1)?1:0);
	else 
		return -1;
}

int seqlist_is_full(seqlist *seq)
{
	if(NULL != seq)
		return ((seq->last == SIZE-1) ?1 : 0);
	else 
		return -1;
}

int getLengthSeqlist(seqlist *seq)
{
	int count = 0;
	if(seqlist_is_empty(seq) == -1)
		return 0;
	else


}

int insrtSeqlist(seqlist *seq, int pos, int number)
{
	int i;
	if(seqlist_is_full(seq))
		return -1;
	int	len = getLengthSeqlist(seq);
	if(pos > len || pos < 0)
		return -1;
	int i = 0;
	for(i=seq->last; i>=pos; i--)
	{
		seq->list[i+1] = seq->list[i];
	}
	seq->list[pos] = data;
	seq->last++; 

	return 0;
}

int DeletePos(seqlist *seq, int pos)
{
	if(seqlist_is_empty(seq))
		return -1;
	if(pos > len || pos < 0)
		return -1;
	int i = 0;
	for(i=pos; i<=seq->last; i++)
	{
		seq->list[i] = seq->list[i+1];
	}
	seq->last--; 

	return 0;
	
}

int DeleteElem(seqlist *seq, int num)
{
	int i;
	if(seqlist_is_empty(seq))
		return -1;
	for(i=0; i<=last; i++)
	{
		if(seq->list[i] == num)
			DeletePos(seq, i);
	}
	
}



int main()
{
	seqlist * seq = createSeqlist();

	if(NULL == seq)
	{
		printf("create seqlist failed\n);
		return -1;
	}


	return 0;
}






