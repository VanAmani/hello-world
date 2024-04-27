#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

typedef struct LNode
{
	char sign;//����
	double coef;//ϵ��
	char alph;//��ĸ
	double exp;//ָ��
	struct LNode* next;
}LNode;

int flag = 0;
char line1[40];
//flag����ȷ���Ƿ�line1[ ]�е��ַ������Ƶ�line[ ]��
//line1[ ]���������洢�ڶ�������ʽ�����ݵ�
LNode* input(LNode* head,const char* name)
{
	LNode* newNode = head;//�� newNode�����ն��׽��ĵ�ַ
	LNode* temp = NULL;
	char coef[10];//�洢ϵ��
	char exp[10];//�洢ָ��
	int cnt = 0;//������׷�� coef �� exp ���ַ������ļ�����
	char line[40];
	FILE* fp = fopen("C:\\main1.txt", "r");
	if (flag == 1)
		strcpy(line, line1);
	else
	{
		fscanf(fp, "%s", line);
		fscanf(fp, "%s", line1);
		flag++;
	}

	strcpy(line, line + 5);//ȥ���ַ�����ǰ׺�� ��a(x)=���͡�b(x)=�� 
	int line_length = strlen(line);//��������ʾ
	if (line_length == 0 ) {
		printf("%s input is empty. Please provide valid input.\n",name);
		return head; 
	}

	int line_cnt = 0;
	while (1)
	{
		//��ȡ������
		if (isdigit(line[line_cnt]) || isalpha(line[line_cnt])) {
			newNode->sign = '+';
		}else{
			newNode->sign = line[line_cnt++];
		}//��ȡ���ϵ��
		if (isdigit(line[line_cnt]))
		{
			while (isdigit(line[line_cnt]) || line[line_cnt] == '.')
			coef[cnt++] = line[line_cnt++];
			coef[cnt] = '\0';//��Ϊ�洢�� coef[ ] �е��ַ��������˽�β
			newNode->coef = strtod(coef,NULL);//���ַ�ת��Ϊ����������
			cnt = 0;
			if (line[line_cnt] == '\0')//��ȡ������
			{
				newNode->exp = 0.0;
				newNode->alph = head->alph;
				newNode->next = NULL;
				break;
			}
		}
		else { newNode->coef = 1; }//ϵ��Ϊ1
		newNode->alph = line[line_cnt];//��ȡ�����ĸ
		if (line[line_cnt + 1] == '^')
		{
			line_cnt += 2;//ʡ��'^'ָ������
			while (isdigit(line[line_cnt]) || line[line_cnt] == '.')
				exp[cnt++] = line[line_cnt++];
			exp[cnt] = '\0';
			newNode->exp = strtod(exp, NULL);//��ȡ���ָ��
			cnt = 0;
			strcpy(exp, "\0");
		}else{
			newNode->exp = 1;
			line_cnt++;
		}
		if (line[line_cnt] == '\0')//����ʽ����
		{
			newNode->next = NULL;
			break;
		}else{
			temp = newNode;
			newNode = (LNode*)malloc(sizeof(LNode));
			temp->next = newNode;
		}
	}
	fclose(fp);
	return head;
}

void output(LNode* head)
{
	LNode* temp_ptr = head;
	FILE* fp = fopen("C:\\main2.txt", "a");
	fprintf(fp, "c(x)=");
	
	while (temp_ptr != NULL)
	{
		//0ϵ�����
		if (temp_ptr->coef != 0) {
			//�������
			if (temp_ptr->sign == '-' || temp_ptr != head)
				fprintf(fp, "%c", temp_ptr->sign);
			//���ϵ��
			double coef = temp_ptr->coef;
			if (temp_ptr->coef != 1 || temp_ptr->exp == 0)
				if (coef - (int)coef == 0)
					fprintf(fp, "%d", (int)coef);
				else
					fprintf(fp, "%.1lf", coef);
			//�����ĸ��ָ��
			if (temp_ptr->exp != 0 && temp_ptr->exp != 1)
			{
				fprintf(fp, "%c^", temp_ptr->alph);
				double exp = temp_ptr->exp;
				if (exp - (int)exp == 0)
					fprintf(fp, "%d", (int)exp);
				else
					fprintf(fp, "%.1lf", exp);
			}
			else if (temp_ptr->exp == 1)//
				fprintf(fp, "%c", temp_ptr->alph);
		}
	
	   temp_ptr = temp_ptr->next;
	}
	fprintf(fp, "\n");
	fclose(fp);
}

void plus(LNode* head1, LNode* head2)
{
	//add list2 and list1 to list3
	LNode* head3 = (LNode*)malloc(sizeof(LNode));
	LNode* newNode = head3;
	LNode* temp = NULL;
	char sign[] = "+1\0";

	while (head1 != NULL || head2 != NULL)
	{
		if (head2 == NULL || head1 != NULL && head1->exp > head2->exp)
		{
			newNode->alph = head1->alph;
			newNode->coef = head1->coef;
			newNode->exp = head1->exp;
			newNode->sign = head1->sign;
			head1 = head1->next;
			temp = newNode;
			newNode = (LNode*)malloc(sizeof(LNode));
			temp->next = newNode;
		}
		else if (head1 == NULL || head2 != NULL && head1->exp < head2->exp)
		{
			newNode->alph = head2->alph;
			newNode->coef = head2->coef;
			newNode->exp = head2->exp;
			newNode->sign = head2->sign;
			head2 = head2->next;
			temp = newNode;
			newNode = (LNode*)malloc(sizeof(LNode));
			temp->next = newNode;
		}
		else
		{
			//���ڵ�ϵ���ͷ�����ϵ��һ��
			sign[0] = head1->sign;//list1
			head1->coef = strtod(sign, NULL) * head1->coef;

			sign[0] = head2->sign;//list2
			head2->coef = strtod(sign, NULL) * head2->coef;

			if (fabs(head1->coef + head2->coef) > 1e-10)
			{
				newNode->sign = (head1->coef + head2->coef) > 0 ? '+' : '-';
				newNode->alph = head1->alph;
				newNode->coef = fabs(head1->coef + head2->coef);//ȡ����ֵ
				newNode->exp = head1->exp;
				temp = newNode;
				newNode = (LNode*)malloc(sizeof(LNode));
				temp->next = newNode;
			}
			else
			{
				newNode->exp = 0;
				newNode->coef = 0;
			}
			head1->coef = fabs(head1->coef);//��ԭ�ڵ�ϵ��
			head2->coef = fabs(head2->coef);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	temp->next = NULL;
	if (newNode != head3)
	{
		free(newNode);
		newNode = NULL;
	}
	output(head3);
}


void minus(LNode* head1, LNode* head2)
{
	LNode* temp = head2;
	while (temp != NULL)
	{
		if (temp->sign == '+')
			temp->sign = '-';
		else
			temp->sign = '+';
		temp = temp->next;
	}
	plus(head1, head2);
	temp = head2;//��ԭ
	while (temp != NULL)
	{
		if (temp->sign == '+')
			temp->sign = '-';
		else
			temp->sign = '+';
		temp = temp->next;
	}
}



void disappear(LNode* head)
{
	LNode* temp = head->next;
	while (temp != NULL)
	{
		free(head);
		head = temp;
		temp = temp->next;
	}
	free(head);
	printf("Free all nodes successfully.\n");
}


void displayMenu() {
	printf("\n");
	printf("\t-------------------------------------------------\n");
	printf("\t|		��ӭʹ�ö���ʽ�������	        |\n");
	printf("\t|	1. ���ļ���ȡ����ʽ 			|\n");
	printf("\t|	2. ִ�ж���ʽ�ӷ�			|\n");
	printf("\t|	3. ִ�ж���ʽ����			|\n");
	printf("\t|	4. �˳�����				|\n");
	printf("\t-------------------------------------------------\n");
	printf("\t��ѡ��������������֣���");
}

int main()
{
	LNode* head1 = (LNode*)malloc(sizeof(LNode));
	LNode* head2 = (LNode*)malloc(sizeof(LNode));

	FILE* fp = fopen("C:\\main2.txt", "w");
	fclose(fp);

	int choice;

	do {
		displayMenu();
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			input(head1, "a(x)");
			input(head2, "b(x)");
			break;
		case 2:
			plus(head1, head2);
			printf("����ʽ�ӷ�����ѱ��浽�ļ� main2.txt��\n");
			break;
		case 3:
			minus(head1, head2);
			printf("����ʽ��������ѱ��浽�ļ� main2.txt��\n");
			break;
		case 4:
			printf("��лʹ�ã��������˳���\n");
			break;
		default:
			printf("��Ч��ѡ�����������롣\n");
		}

	} while (choice != 4);
	
	disappear(head1);
	disappear(head2);


	return 0;
}


