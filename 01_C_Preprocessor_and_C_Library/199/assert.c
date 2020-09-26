#include <stdio.h>
#include <assert.h>
//#define NDEBUG

int main(void)
{
	int i;
	int a[5]={2,4,6,8,10};
	for(i=0; i<=5; i++)
	{
		//#ifdef NDEBUG
			assert(i>=0 && i<5);	//�����߮ɡA����{��
		//#endif
		printf("[%d]=%d\n", i, a[i]);
	}
	return 0;
}


