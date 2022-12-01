#include <iostream.h>
#include <time.h> // for GenIntArray/GenRealAraay
#include <stdlib.h> // for GenIntArray/GenRealAraay

//a. Ввод действительного числа с контролем
double InReal(double left,double right)
{
	double in;

	do
	{
		scanf("%lf",&in);
	}
	while(in < left || in > right);

	return in;
}

//b. Ввод целого числа с контролем
int InInt(int left,int right)
{
	int in;

	do
	{
		scanf("%d",&in);
	}
	while(in < left || in > right);

	return in;
}


//c. Ввод, вывод действительного массива
void InRealArray(double *Array,int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%lf",&Array[i]);

	} 
}
void OutRealArray(double Array[], int n)
{
	for(int i = 0; i < n; i++) cout << Array[i];

	cout << "\n";
}

//d. Ввод, вывод целочисленного массива
void InIntArray(int *Array,int n)
{
	for(int i = 0; i < n; i++) cin >>Array[i];

	
}

void OutIntArray(int Array[], int n)
{
	for(int i = 0; i < n; i++) cout << Array[i];

	cout << "\n";
}


//Генерация значений действительного массива
void GenRealArray(double *Array,int n)
{
	for(int i = 0; i < n; i++) Array[i] =(double) rand() * rand() / rand();

}

//f. Генерация значений целочисленного массива
void GenIntArray(int *Array,int n)
{
	for(int i = 0; i < n; i++) Array[i] = rand();

}

int MaxIndexInt(int Array[],int n)
{
	int Max = Array[0],index = 0;

	for(int i  = 1; i < n; i++)
	{
		if(Array[i] > Max)
		{
			Max = Array[i];
			index = 0;
		}
	}
	return index;
}

int MinIndexInt(int Array[],int n)
{
	int Min = Array[0],index = 0;

	for(int i  = 1; i < n; i++)
	{
		if(Array[i] < Min)
		{
			Min = Array[i];
			index = 0;
		}
	}
	return index;
}

int MaxIndexReal(double Array[],int n)
{
	double Max = Array[0];
	int index = 0;

	for(int i  = 0; i < n; i++)
	{
		if(Array[i] > Max)
		{
			Max = Array[i];
			index = 0;
		}
	}
	return index;
}

int MinIndexReal(double Array[],int n)
{
	double Min = Array[0];
	int index = 0;

	for(int i  = 0; i < n; i++)
	{
		if(Array[i] < Min)
		{
			Min = Array[i];
			index = 0;
		}
	}
	return index;
}

void SortInt(int *Array,int n){
	int elem;

	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++)
		{
			if (Array[i] > Array[j])
			{
				elem = Array[i];
				Array[i] = Array[j];
				Array[j] = elem;
			} 
		}
}

void SortReal(double *Array,int n){
	double elem;

	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++)
		{
			if (Array[i] > Array[j])
			{
				elem = Array[i];
				Array[i] = Array[j];
				Array[j] = elem;
			} 
		}

}