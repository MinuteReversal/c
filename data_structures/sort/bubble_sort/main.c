
#include <stdio.h>
int main()
{

	int a[] = { 7, 8, 2, 4, 6 };
	int length = sizeof(a) / sizeof(int);
	for (size_t i = 0; i < length-1;  i++)
	{
		for(size_t j=0;j<length-1;j++)
		{
			if(a[j+1]<a[j])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<length;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
