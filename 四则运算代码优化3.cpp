#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int right=0;
int wrong=0;
	int numb1,numb2,i;		//随机生成的数值
	int op1;					//运算符
	FILE *fp;//定义文件流指针
	FILE *fb;
	

	int operationone(int numb1,int numb2,int max,int i)	
	{	
		int gcd(int numb1,int numb2);                                                            
		int temp;//中间值
		int result;
		op1=rand()%4+1;	//op1的生成值为1到4，分别对应加法，减法，乘法，除法
		fb=fopen("Exercises.txt","a");
		fp=fopen("Answers.txt","a");//打开文件
		switch(op1){
			case 1:		//op1为1的时候，执行加法操作
			
				
				while (numb1+numb2>100)
				{

				   numb1=rand()%100+1;
				   numb2=rand()%100+1;
			
				}
			
					
				printf("题目%d:%d+%d=",i,numb1,numb2);
				fprintf(fb,"题目%d:%d+%d=\n",i,numb1,numb2);		
			    fclose(fb);	
			
				scanf("%d",&result);
				if((numb1+numb2)==result)
				{
					printf("回答正确!\n");

				    right++;
				 }
				else
				{
					 printf("回答错误!\n");
					 wrong++;
				}
				fprintf(fp,"题目%d:%d+%d=%d\n",i,numb1,numb2,numb1+numb2);		//写入文件
			    fclose(fp);			//关闭文件
			
				break;
			case 2 :           //op1为2的时候，执行减法操作；
				
				if(numb1<numb2)		//为保证结果不为零，当出现生成的被减数比减数小，进行两者值的交换
				{
				temp=numb1;
				numb2=numb1;
				numb1=temp;
				}
				printf("题目%d:%d-%d=",i,numb1,numb2);
			
			fprintf(fb,"题目%d:%d-%d = \n",i,numb1,numb2);
			    fclose(fb);
					scanf("%d",&result);
				if((numb1-numb2)==result)
				{
					printf("回答正确!\n");


				    right++;
				 }
				else
				{
					 printf("回答错误!\n");
					 wrong++;
				}
					fprintf(fp,"题目%d:%d-%d = %d\n",i,numb1,numb2,numb1-numb2);
			    fclose(fp);
				
				break;
			case 3 :		//op1为3的时候，执行乘法操作；
		

				
			while (numb1*numb2>100)
				{
					numb1=rand()%max+1;
				   numb2=rand()%max+1;
				
				}
			 printf("题目%d:%d*%d=",i,numb1,numb2);
				fprintf(fb,"题目%d:%d-%d = \n",i,numb1,numb2);
			    fclose(fb);
					scanf("%d",&result);
				if((numb1*numb2)==result)
				{
					printf("回答正确!\n");


				    right++;
				 }
				else
				{
					 printf("回答错误!\n");
					 wrong++;
				}
				fprintf(fp,"题目%d:%d*%d = %d\n",i,numb1,numb2,numb1*numb2);
			    fclose(fp);
				

				break;
			case 4 :    //op1为4的时候，执行除法操作；


				//除法结果不为分数和小数时
				  

              while(numb1%numb2!=0)
				{numb1=rand()%100+1;
				numb2=rand()%100+1;
				}
			
				printf("题目%d:%d/%d=",i,numb1,numb2);
			
				fprintf(fb,"题目%d:%d/%d = \n",i,numb1,numb2);
			    fclose(fb);
		
				scanf("%d",&result);
				if(numb1/numb2==result)
				{
					printf("回答正确!\n");


				    right++;
				 }
				else
				{
					 printf("回答错误!\n");
					 wrong++;
				}
				fprintf(fp,"题目%d:%d/%d = %d/%d\n",i,numb1,numb2,numb1/temp,numb2/temp);
			    fclose(fp);
				
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
	
		for(i=1;i<=subnumber;i++)		//for循环生成题目
		{
			
									//当随机数是生成1个运算符时
				numb1=rand()%100+1;
				numb2=rand()%100+1;
				operationone(numb1,numb2,max,i);		//执行函数的同时得同时执行把表达式输出到txt文件中
			
		}
		printf("您总共完成了 %d 道题\n正确 %d 道\n错误 %d 道\n总分为 %d\n",right+wrong,right,wrong,right*10+wrong*0);
		return 0;
	}
