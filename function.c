#include"telbook.h"
int arrnum = 2; 
//���뺯��
struct item* insert(struct item* N, int x)
{
	int i = 0;
	//����λ�����
	if (x<1 || x>MAXPERSON)
	{
		puts("����λ�ò��Ϸ�!");
		exit(1);
	}
	//����λ���ڱ߽�
	else if (x == MAXPERSON)
	{
		int i;
		int s;
		struct item* p;
		//arrnum��ʼΪ2,��ʼ�����1
		p = (struct item*)malloc(sizeof(struct item) * MAXPERSON * arrnum);
		arrnum++;
		//�����ƶ���������
		for (i = 0;i < x;i++)
		{
			*N = *p;
			N++;
			p++;
		}
		free(N);
		//�ж������Ƿ��д���
		s = get(&p[x-1]);
		if (!s)
		{
			puts("�������");
			exit(1);
		}
		return p;
	}
	//����λ����һ����ʮ��
	else
	{
		int s = 1;
		//�ж������Ƿ��д���
		s = get(&N[x-1]);
		if (!s)
		{
			puts("�������");
			exit(1);
		}
	}
}
//��ʼ������
struct item* init(void)
{
	struct item* N;
	puts("��ʼ���绰��");
	N = (struct item*)malloc(sizeof(struct item)*MAXPERSON);
	if (N)
		puts("��ʼ���ɹ���");
	else
	{
		puts("��ʼ������");
		exit(1);
	}
	return N;
}
//���뺯�������ж������±꣬�ṩ����
int  get(struct item* L)
{
	printf("����������:\n");
	s_gets(L->name, MAXSIZE);
	//name��ʼ��Ϊ0������ɹ��Ͳ���0����ͬ
	if (L->name[0])
	{
		puts("��������ɹ���");
	}
	else
	{
		printf("\n�����������\n");
		return 0;
	}
	puts("����������绰����:");
	s_gets(L->telnumber, TELSIZE);
	if (L->telnumber[0])
	{
		puts("�绰��������ɹ���");
	}
	else
	{
		puts("�绰�����������");
		return 0;
	}
	return 1;
}
//ɾ���������ж������±�
int delete (struct item* N, int x)
{
	int i;
	struct item* p;
	checknum(x);
	p = &N[x-1];
	printf("\n��ʼɾ����%dλ�绰����ϵ�˵�����\n",x);
	for (i = 0;i < MAXSIZE;i++)
		p->name[i] = '\0';
	puts("��ʼɾ���绰����\n");
	for (i = 0; i < TELSIZE; i++)
		p->telnumber[i] = '\0';
	//��memset(p->name,0,sizeof(p->name));

	//������ֻ��������һλ�Ƿ�����
	if (p->name[MAXSIZE - 1] && p->telnumber[TELSIZE - 1])
	{
		puts("\nɾ��ʧ�ܣ�\n");
		return 0;
	}
	else
		puts("ɾ���ɹ�!");
		return 1;
}
//�޸ĺ������жϽṹ�����±�
int revise(struct item* N, int x)
{
	int s;

	printf("\n��ʼ�޸ĵ�%dλ�绰����ϵ��\n", x);
	checknum(x);
	s = get(&N[x-1]);
	//�����뺯���ж��Ƿ��޸ĳɹ�
	if (!s)
	{
		puts("\n�޸Ĵ���\n");
		exit(1);
	}
}

//ͨ��λ�ò�����ϵ��
struct item* checkbyloaction(struct item* N, int x)
{
	struct item* p;
	checknum(x);
	p = &N[x-1];
	if (p)
		printf("��%dλ��ϵ�ˣ����ҳɹ���", x);
	else
		return 0;
	
	if (p->name[0] && p->telnumber[0])
	{
		printf("������ϵ����%s\n", p->name);
		printf("%s�ĵ绰������%s\n", p->name, p->telnumber);
	}
	else
		puts("\n��������ϵ��");
	return p;
}

//ͨ�����ֲ�����ϵ��
struct item* checkname(struct item* N)
{
	char name[MAXSIZE];
	int i = 1;
	struct item* p;
	p = &N[0]; //ָ�붨��

	//��ȡ���Ƚϵ�����
	puts("����������");
	s_gets(name, MAXSIZE);

	while (strcmp(p->name, name) != 0 && i <= MAXPERSON)
	{
		p++;
		i++;
	}
if (p && i<= MAXPERSON)
	{
		puts("���ҳɹ���");
		printf("��%dλ��ϵ��%s�ĵ绰������%s\n",i, 
			p->name, p->telnumber);
		return p;
	}
	else
	{
		puts("�޴���ϵ��!");
		return 0;
	}
}

//ͨ���绰���������ϵ��
struct item* checktelnum(struct item* N)
{
	char telnum[TELSIZE];
	int i = 1;
	struct item* p;
	p = &N[0];

	//��ȡ���Ƚϵĵ绰����
	puts("������绰����");
	s_gets(telnum,TELSIZE);

	while (strcmp(p->telnumber,telnum) != 0 && i <= MAXPERSON)
	{
		p++;
		i++;
	}
	if (p && i <= MAXPERSON)
	{
		puts("���ҳɹ���");
		printf("�绰����Ϊ%s����ϵ����%s��Ϊ��%dλ��ϵ��\n",
			p->telnumber,p->name, i);
		return p;
	}
	else
	{
		puts("�޴���ϵ��!");
		return 0;
	}
}

//���벢����ַ���
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}

//��ӡ��������ӡ������ϵ��
void print(struct item* N)
{
	int flag = 0;
	int i = 1;
	struct item* p;
	p = &N[0];
	puts("��ʼ��ӡȫ����ϵ��");
	while (p && i <= MAXPERSON)
	{
		if (p->telnumber[0] >= '0' && p->telnumber[0] <= '9')
		{
			printf("��%dλ��ϵ�ˣ�%s,�绰������%s\n",
				i, p->name, p->telnumber);
			flag = 1;
		}
		else
		{
			//�����ظ���ӡ
			if(flag)
				puts("��λ����ϵ�ˣ�");
			flag = 0;
		}
		p++;
		i++;
	}
	printf("��ӡ���!\n");
	return 0;
}

//��������λ���Ƿ�Ϸ�
void checknum(int x)
{
	//x����100ʱ��ֻ���������������޸�
	if (x < 1 ||
		(x > MAXPERSON && arrnum == 2) || x>MAXPERSON*arrnum)
	{
		puts("�޸�λ�ò��Ϸ���");
		exit(1);
	}
}

//�˵��������ṩѡ��������ת�͸��߼��Ļ���
int menu(struct item* N)
{
	char mark[15] = "**************";
	char s;

	printf("\n\n\n\n\n");
	printf("%+20s�˵�����%-20s\n\n",mark,mark);
	printf("%+20s������ϵ�˰�\"a\"%-20s\n\n",mark,mark);
	printf("%+20sɾ����ϵ�˰�\"b\"%-20s\n\n", mark, mark);
	printf("%+20s�޸���ϵ�˰�\"c\"%-20s\n\n", mark, mark);
	printf("%+20s��λ�ò�����ϵ�˰�\"d\"%-20s\n\n", mark, mark);
	printf("%+20s�����ֲ�����ϵ�˰�\"e\"%-20s\n\n", mark, mark);
	printf("%+20s�õ绰���������ϵ�˰�\"f\"%-20s\n\n", mark, mark);
	printf("%+20s��ӡȫ����ϵ�˰�\"g\"%-20s\n\n", mark, mark);
	printf("%+20s�˳��˵���\"n\"%-20s\n\n", mark, mark);

	printf("\n���������Ĳ���:\n");
	while ((s = getchar()) == '\n')
		continue;

	while (1)
	{
		switch (s)
		{
		case 'a':
		{
			int i = 1;
			puts("\n��Ҫ�½��ڼ�λ��ϵ��:");
			if (scanf("%d", &i) == 0)
			{
				puts("�������");
				free(N);
				exit(1);
			}
			getchar();
			flag = insert(N, i);
			menu(N);//����nʱ����
			break;
		}
		case 'b':
		{
			int i = 0;
			puts("\n��Ҫɾ���ڼ�λ��ϵ��:");
			if (scanf("%d",&i) == 0)
			{
				puts("������������ԣ�");
				free(N);
				exit(1);
			}
			getchar();
			delete(N, i);
			menu(N);
			break;
		}
		case 'c':
		{
			int i = 0;
			puts("\n��Ҫ�޸ĵڼ�λ��ϵ��:");
			if (scanf("%d", &i) == 0)
			{
				puts("������������ԣ�");
				free(N);
				exit(1);
			}
			getchar();
			revise(N, i);
			menu(N);
			break;
		}
		case 'd':
		{
			int i = 0;
			puts("��ʼ����");
			puts("��������ϵ�˵�λ��:");
			if (scanf("%d", &i) == 0)
			{
				puts("�������,������!");
				free(N);
				exit(1);
			}
			getchar();
			checkbyloaction(N, i);
			menu(N);
			break;
		}
		case 'e':
		{
			puts("��ʼ����");
			getchar();
			checkname(N);
			menu(N);
			break;
		}
		case 'f':
		{
			puts("��ʼ����");
			getchar();
			checktelnum(N);
			menu(N);
			break;
		}
		case 'g':
		{
			print(N);
			menu(N);
			break;
		}
		case 'n':
		{
			puts("�ټ���");
			free(N);
			exit(1);
		}
		default:
		{
			puts("�����������!\n");
			exit(1);
		}
		}
	}
}