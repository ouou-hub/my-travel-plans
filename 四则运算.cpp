#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "miniunit.h"

int right=0;

int wrong=0;
	int numb1,numb2,i;		     //������ɵ���ֵ
	int op1;					//�����
	FILE *fp;                  //�����ļ���ָ��
	FILE *fb;
	

int test(int numb1,int numb2,int max,int i)	
{	
	int gcd(int numb1,int numb2);                                                            
	int temp;//�м�ֵ
	int result;
	op1=rand()%4+1;	//op1������ֵΪ1��4���ֱ��Ӧ�ӷ����������˷�������
	fb=fopen("Exercises.txt","a");
	fp=fopen("Answers.txt","a");//���ļ�
	switch(op1)
	{
	case 1:		
		while (numb1+numb2>100)
		{
			numb1=rand()%100+1;
			numb2=rand()%100+1;
		}
		printf("��Ŀ%d:%d+%d=",i,numb1,numb2);
		fprintf(fb,"��Ŀ%d:%d+%d=\n",i,numb1,numb2);		
		fclose(fb);	
		scanf("%d",&result);
		if((numb1+numb2)==result)
		{
			printf("�ش���ȷ!\n");
			right++;
		}
		else
		{ 
			printf("�ش����!\n");
			printf("��ȷ����:%d",numb1+numb2);
			printf("\n");
			wrong++;
		}
		fprintf(fp,"��Ŀ%d:%d+%d=%d\n",i,numb1,numb2,numb1+numb2);		//д���ļ�
		fclose(fp);			   //�ر��ļ�
		break;
	case 2 :                  //op1Ϊ2��ʱ��ִ�м���������
		if(numb1<numb2)		  //Ϊ��֤�����Ϊ�㣬���������ɵı������ȼ���С����������ֵ�Ľ���
		{
			temp=numb1;
			numb2=numb1;
			numb1=temp;
		}
		printf("��Ŀ%d:%d-%d=",i,numb1,numb2);
		fprintf(fb,"��Ŀ%d:%d-%d = \n",i,numb1,numb2);
		fclose(fb);
		scanf("%d",&result);
		if((numb1-numb2)==result)
		{
			printf("�ش���ȷ!\n");
			right++;
		}
		else
		{
			printf("�ش����!\n");
			printf("��ȷ����:%d",numb1-numb2);
			printf("\n");
			wrong++;
		}
		fprintf(fp,"��Ŀ%d:%d-%d = %d\n",i,numb1,numb2,numb1-numb2);
		fclose(fp);
		break;
	case 3 :		    //op1Ϊ3��ʱ��ִ�г˷�������
		while (numb1*numb2>100)
		{
			numb1=rand()%max+1;
			numb2=rand()%max+1;
		}
		printf("��Ŀ%d:%d*%d=",i,numb1,numb2);
		fprintf(fb,"��Ŀ%d:%d-%d = \n",i,numb1,numb2);
		fclose(fb);
		scanf("%d",&result);
		if((numb1*numb2)==result)
		{
			printf("�ش���ȷ!\n");
			right++;
		}
		else
		{
			printf("�ش����!\n");
			printf("��ȷ����:%d",numb1*numb2);
			printf("\n");
			wrong++;
		}
		fprintf(fp,"��Ŀ%d:%d*%d = %d\n",i,numb1,numb2,numb1*numb2);
		fclose(fp);
		break;
	case 4 :    
		while(numb1%numb2!=0)
		{
			numb1=rand()%100+1;
			numb2=rand()%100+1;
		}
		printf("��Ŀ%d:%d/%d=",i,numb1,numb2);
		fprintf(fb,"��Ŀ%d:%d/%d = \n",i,numb1,numb2);
		fclose(fb);
		scanf("%d",&result);
		if(numb1/numb2==result)
		{
			printf("�ش���ȷ!\n");
			right++;
		}
		else
		{
			printf("�ش����!\n");
			printf("��ȷ����:%d",numb1/numb2);
			printf("\n");
			wrong++;
		}
		fprintf(fp,"��Ŀ%d:%d/%d = %d/%d\n",i,numb1,numb2,numb1/temp,numb2/temp);
		fclose(fp);
		break;
	default:printf("ERROR\n");
    }
	for(int a=1;a<=10;a++)
	{
		mu_run_test(test(n));
	}
    return 0;
}

int main()
{
	int subnumber,max;
	int operationone(int numb1,int numb2,int max,int i);		//����������
	FILE *fp;
	fp=fopen("Exercises.txt","w");
	fp=fopen("Answers.txt","w");			//�����ļ�
	fclose(fp);
	srand((unsigned)time(0));				//Ϊ��֤ÿ�����г����ʱ�����ɵ���Ŀ����һ��
	printf("************�����������������Ŀ************\n");
	printf("��������Ŀ������\n");
	scanf("%d",&subnumber); 
	for(i=1;i<=subnumber;i++)		//forѭ��������Ŀ
	{
		numb1=rand()%100+1;
		numb2=rand()%100+1;
		operationone(numb1,numb2,max,i);		//ִ�к�����ͬʱ��ͬʱִ�аѱ��ʽ�����txt�ļ���
	}
	printf("���ܹ������ %d ����\n��ȷ %d ��\n���� %d ��\n�ܷ�Ϊ %d\n",right+wrong,right,wrong,right*10+wrong*0);
	mu_test_results():
	return 0;
}
