#include"telbook.h"
int main(void)
{	
	char s;
	struct item* telbook;
	int flag = 1;

	puts("�Ƿ��ʼ���绰��(y or n)");
	while ((s = getchar()) == '\n')
		continue;
	if (s == 'y')
	{
		telbook = init();
		menu(telbook);
	}
	else
	{
		printf("���!\n");
	}
	return 0;
}