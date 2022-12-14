#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ii = 0;

int testSort(int Array[],int size)
{
	for (int i = 1; i < size; i++)
	{
		if (Array[i] < Array[i-1])
		{
			return i;
		}
	}

	return 0;
}

int MinElemArray(int Array[],int size,int *index)
{
	int min = Array[*index],c = 0;

	for (int i = *index + 1; i < size; i++)
	{
		c++;
		if (min > Array[i])
		{
			min = Array[i];
			*index = i;
		}
	} 

	return c;
}

void InIntArray(int *Array,int n)
{
	for (int i = 0; i < n; i++) scanf("%d",&Array[i]);
}

void CopyArray(int* Copy,int Original[],int size)
{
	for (int i = 0; i < size; i++)
	{
		Copy[i] = Original[i];
	}
}

void swap(int *a,int *b)
{
	int elem;
	elem = *a;
	*a = *b;
	*b = elem;
}

// ÂŁÂĄÂ­ÂĄĂ Â Ă¦Â¨ĂŻ Ă§Â¨ĂˇÂ«Â  (int) Â˘ ÂŻĂ ÂĄÂ¤ÂĄÂ«Â ĂĄ [left,right]
int GenInt(int left, int right)
{
    int genint = (int)((right - left) * ((double)rand() / RAND_MAX) + left);

    return genint;
}

// ÂŁÂĄÂ­ÂĄĂ Â Ă¦Â¨ĂŻ Â¬Â ĂˇĂˇÂ¨Â˘Â  (int) Â˘ ÂŻĂ ÂĄÂ¤ÂĄÂ«Â ĂĄ [left,right]
void GenIntArray(int* arr, int size, int left, int right)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = GenInt(left, right);
    }
}

// || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || 
// || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || || ||
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/

int SortChoice(int *Array,int size,int *c1)
{
	int c = 0,min_of_part;

	for (int i = 0; i < size; i++)
	{	
		min_of_part = i;

		c += MinElemArray(Array,size,&min_of_part);

		swap(&Array[i], &Array[min_of_part]);
		*c1 += 1;
		
	}

	return c;
}

int SortBubbel(int *A,int n,int *c1)
{
	int c = 0;

	*c1 = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			c++;

			if (A[j] > A[j+1])
			{
				swap(&A[j], &A[j + 1]);
				*c1 = *c1 + 1;
			}
		}
	}
	return c;
}

int SortInsert(int *A,int n,int *c1)
{
	int elem,c = 0,j;

	*c1 = 0;

	for (int i = 0; i < n; i++)
	{
		elem = A[i];
		j = i;

		if (j < 0 || A[j - 1] < elem)
		{
			c++;
		}


		while(j > 0 && A[j - 1] > elem) 
		{
			c++;
			*c1 = *c1 + 1;
			A[j] = A[j - 1];
			j = j - 1;
		}
		A[j] = elem;
	}
	return c;
}

void MyQsort(int* arr, int b, int e,int *c1,int *c)
{
    int l = b, r = e;
    int piv;
    piv = arr[(l + r) / 2]; 

    while (l <= r)
    {
        while (arr[l] < piv)
        {
            l++;
            *c = *c + 1;
        }
        while (arr[r] > piv)
        {
            r--;
            *c = *c + 1;
        }
        if (l <= r)
        {
        	*c = *c + 1;
        	*c1 = *c1 + 1;
            swap(&arr[l++], &arr[r--]);
        }
    }
    if (b < r)
        MyQsort(arr, b, r, c1, c);
    if (e > l)
        MyQsort(arr, l, e, c1, c);
}

int cmp(const void *a, const void *b) 
{
	ii++;
	return *(int*)a - *(int*)b; 
}

void gnomesort(int* pl, int* pr,int * c,int * c1) {
	int *i = pl;
	*c = 0;
	*c1 = 0;
	while (i < pr) {
		*c = *c + 1;
		if (i == pl || *(i - 1) <= *i) i++;
		else 
		{
			*c1 = *c1 + 1;
			swap(&*(i - 1),&*i);
			i--;
		}
	}
}

int main()
{
	srand(time(0));

	int size,l,r,Operations = 0,OperationsChanges = 0,start,end;

	double time;

	scanf("%d%d%d",&size,&l,&r);

	int Array[size],Copy[size];

	GenIntArray(Array,size,l,r);



	//â€ Â®Ă˘Â¨Ă Â®Â˘ÂŞÂ  Â˘Ă«ÂˇÂ®Ă Â®Â¬
	printf("\nСортировка вбором ----------------------------------\n");

	CopyArray(Copy,Array,size);

	start = clock();
	Operations = SortChoice(Copy,size,&OperationsChanges);
	end = clock();

	time =  (double) (end - start) /  CLOCKS_PER_SEC;
	
	printf("Check_Result = %d\n",testSort(Copy,size));

	printf("Operations All = %d || Operations Chenges = %d || Time = %lf sek \n",Operations,OperationsChanges,time);



	//â€ Â®Ă˘Â¨Ă Â®Â˘ÂŞÂ  ÂŻĂŁÂ§Ă«Ă Ă¬ÂŞÂ®Â¬
	printf("\n Сортировка пузырьком ----------------------------------\n");

	CopyArray(Copy,Array,size);

	start = clock();
	Operations = SortBubbel(Copy,size,&OperationsChanges);
	end = clock();

	time =  (double) (end - start) /  CLOCKS_PER_SEC;

	printf("Check_Result = %d\n",testSort(Copy,size));
	
	printf("Operations All = %d || Operations Chenges = %d || Time = %lf sek \n",Operations,OperationsChanges,time);



	//â€ Â®Ă˘Â¨Ă Â®Â˘ÂŞÂ  Â˘ĂˇĂ˘Â Â˘ÂŞÂ Â¬Â¨
	printf("\n Сортировка вставками ----------------------------------\n");

	CopyArray(Copy,Array,size);

	start = clock();
	Operations = SortInsert(Copy,size,&OperationsChanges);
	end = clock();

	time =  (double) (end - start) /  CLOCKS_PER_SEC;

	printf("Check_Result = %d\n",testSort(Copy,size));
	
	printf("Operations All = %d || Operations Chenges = %d || Time = %lf sek \n",Operations,OperationsChanges,time);

	//Â Ă«ĂˇĂ˘Ă Â ĂŻ ĂˇÂ®Ă Ă˘Â¨Ă Â®Â˘ÂŞÂ 
	printf("\n Быстрая сортирока (Моя) ----------------------------------\n");

	CopyArray(Copy,Array,size);

	OperationsChanges = 0;
	Operations = 0;

	start = clock();
	MyQsort(Copy,0,size - 1 ,&OperationsChanges,&Operations);
	end = clock();

	time =  (double) (end - start) /  CLOCKS_PER_SEC;

	printf("Check_Result = %d\n",testSort(Copy,size));
	
	printf("Operations All = %d || Operations Chenges = %d || Time = %lf sek \n",Operations,OperationsChanges,time);

	//â€ Â¨ĂˇĂ˘ÂĄÂ¬Â­Â ĂŻ ÂˇĂ«ĂˇĂ˘Ă Â ĂŻ ĂˇÂ®Ă Ă˘Â¨Ă Â®Â˘ÂŞÂ 
	printf("\n Быстрая сортировка (qsort)  ----------------------------------\n");

	CopyArray(Copy,Array,size);

	start = clock();
	qsort(Copy, size, sizeof(int),cmp);
	end = clock();

	time =  (double) (end - start) /  CLOCKS_PER_SEC;

	printf("Check_Result = %d\n",testSort(Copy,size));

	printf("Operations All = %d || Operations Chenges = DONT_KONOW || Time = %lf sek \n",ii,time);

	//Ć’Â­Â®Â¬Ă¬ĂŻ ĂˇÂ®Ă Ă˘Â¨Ă Â®Â˘ÂŞÂ 
	printf("\n Гномья сортировка / Gnome sort ----------------------------------\n");

	CopyArray(Copy,Array,size);

	start = clock();
	gnomesort(&Copy[0],&Copy[size],&Operations,&OperationsChanges);
	end = clock();

	time =  (double) (end - start) /  CLOCKS_PER_SEC;

	printf("Check_Result = %d\n",testSort(Copy,size));

	printf("Operations All = %d || Operations Chenges = %d || Time = %lf sek \n",Operations,OperationsChanges,time);

	return 0;
}