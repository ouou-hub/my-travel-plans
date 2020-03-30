#include<stdio.h>
#include <stdlib.h>
#include <time.h>
	int numb1,numb2,i;		//随机生成的数值
	int op1;					//运算符
	FILE *fp;//定义文件流指针
	FILE *fb;
	int gcd(int numb1,int numb2)//辗转相除法 
	{
		if(numb2==0) return numb1;
		return	gcd(numb2,numb1%numb2);
	}
//在屏幕上没有显示题目，答题，对错，得分
	int operationone(int numb1,int numb2,int max,int i)	//不一定是整型函数
	{	
		int gcd(int numb1,int numb2);                                                            
		int temp;//中间值
		int result;
		op1=rand()%4+1;	//op1的生成值为1到4，分别对应加法，减法，乘法，除法
		fb=fopen("Exercises.txt","a");
		fp=fopen("Answers.txt","a");//打开文件
		switch(op1){
			case 1:		//op1为1的时候，执行加法操作
				result=numb1+numb2;
				
				/*
			和不能大于一百
					*/
				fprintf(fp,"题目%d:%d+%d=%d\n",i,numb1,numb2,result);		//写入文件
			    fclose(fp);			//关闭文件
				fprintf(fb,"题目%d:%d+%d=\n",i,numb1,numb2);		
			    fclose(fb);	
			
				break;
			case 2 :		//op1为2的时候，执行减法操作；
				if(numb1<numb2)		//为保证结果不为零，当出现生成的被减数比减数小，进行两者值的交换
				{
				temp=numb1;
				numb2=numb1;
				numb1=temp;
				}
				result=numb1-numb2;
				fprintf(fp,"题目%d:%d-%d = %d\n",i,numb1,numb2,result);
			    fclose(fp);
				fprintf(fb,"题目%d:%d-%d = \n",i,numb1,numb2);
			    fclose(fb);
				break;
			case 3 :		//op1为3的时候，执行乘法操作；
			  
				result=numb1*numb2;

					/*
			结果不能大于100
					*/
				fprintf(fp,"题目%d:%d*%d = %d\n",i,numb1,numb2,result);
			    fclose(fp);
				fprintf(fb,"题目%d:%d*%d = \n",i,numb1,numb2);
			    fclose(fb);

		
				break;
			case 4 :    //op1为4的时候，执行除法操作；


				//除法结果不为分数和小数时
				/*
		            */
				if(numb2==0)
					numb2=rand()%max+1;
				temp=gcd(numb1,numb2);
				fprintf(fp,"题目%d:%d/%d = %d/%d\n",i,numb1,numb2,numb1/temp,numb2/temp);
			    fclose(fp);
				fprintf(fb,"题目%d:%d/%d = \n",i,numb1,numb2);
			    fclose(fb);
				break;
			default:printf("ERROR\n");
		}
		return 0;
	}
int main()
	{
		int subnumber,max;
	
		int operationone(int numb1,int numb2,int max,int i);		//函数的声明
		
		FILE *fp;
		fp=fopen("Exercises.txt","w");
		fp=fopen("Answers.txt","w");			//建立文件
		fclose(fp);
		srand((unsigned)time(0));				//为保证每次运行程序的时候生成的题目都不一样
		printf("************随机生成四则运算题目************\n");
		printf("请输入题目数量：\n");
		scanf("%d",&subnumber); 
		printf("请输入生成的随机数范围大小：\n");
		scanf("%d",&max); 
		for(i=1;i<=subnumber;i++)		//for循环生成题目
		{
								//当随机数是生成1个运算符时
				numb1=rand()%max;
				numb2=rand()%max;
				operationone(numb1,numb2,max,i);		//执行函数的同时得同时执行把表达式输出到txt文件中
			
		}
		return 0;
	}
