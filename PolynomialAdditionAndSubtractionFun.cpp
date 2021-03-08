//类成员函数的实现
#include "PolynomialAdditionAndSubtraction.h"
#include <iostream>
#include <windows.h>
using namespace std;


Data* Data::insert(float c,int e)                                             //调用此函数在this指针指向的项的后面插入新项 
{
	link=new Data(c,e,link);
	return link;
}


Polynomal Polynomal::Execute()                                                //主体部分：创建多项式并执行相加减操作
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);//修改字体颜色，在windows.h中定义 
	cout<<"本程序可以实现对多项式的加减运算\n";
	cout<<"注意：输入多项式时要根据指数从小到大输入！\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
	while(1)
	{
	    float coef;       int exp,i,z,y;
	    Data* A=nullptr;  Data* B=nullptr;
	    Polynomal Z;      A=Z.first;
	    Polynomal Y;      B=Y.first;
	
	    cout<<"请输入多项式A的项数：";
	    cin>>z;
	    cout<<"请依次输入多项式A的系数和指数：\n";
	    for(i=0;i<z;i++)
	    {
		    cin>>coef>>exp;
		    A=A->insert(coef,exp);
	    }
	
	    cout<<"请输入多项式B的项数：";
	    cin>>y;
	    cout<<"请依次输入多项式B的系数和指数：\n";
	    for(i=0;i<y;i++)
	    {
		    cin>>coef>>exp;
		    B=B->insert(coef,exp);
	    }

	    Polynomal X,W,V;
	    int flag1;
	    cout<<"请输入您要执行的操作（1.做加法 2.做减法）：";
	    cin>>flag1;
	    while(1)
	    {
	        if(flag1==1)
	        {
	    	    W=X.Add(Z,Y);
	    	    for(A=W.Gethead()->link;A!=nullptr;A=A->link)
	            {
		            cout<<A->coef<<"  "<<A->exp<<"\n";
	            }
	            break;
		    }
	    	else if(flag1==2)
	     	{
		    	V=X.Subtract(Z,Y);
			    for(B=V.Gethead()->link;B!=nullptr;B=B->link)
	            {
		            cout<<B->coef<<"  "<<B->exp<<"\n"; 
	            }
	            break;
		    }
		    else
		    {
		    	cout<<"错误指令！请重新输入！";
			    cin>>flag1;
		    	continue;
		    }
	    }
	    
	    char flag2;
	    cout<<"是否继续运算(Y/N): ";
	    cin>>flag2;
	    if(flag2=='n'||flag2=='N')
	    {
	    	cout<<endl;
	    	cout<<"感谢使用！\n";
	    	system("pause");
	    	break;
		}
    }
}


Polynomal Polynomal::Add(Polynomal& A,Polynomal& B)        //相加 
{
	Data *pa,*pb,*pc,*p1;
	float temp;
	Polynomal C;  pc=C.first;
	pa=A.Gethead()->link;  pb=B.Gethead()->link;           //分别指向AB第一个节点
	
	while(pa!=nullptr && pb!=nullptr)
	{
		if(pa->exp > pb->exp)                              //当pb指数小 
		{
			pc=pc->insert(pb->coef,pb->exp);
			pb=pb->link;
		}
		else if(pa->exp == pb->exp)                       //当两者指数相等 
		{
			temp=pa->coef+pb->coef;
			if(temp != 0)
			{
				pc=pc->insert(temp,pa->exp);
			}
			pa=pa->link;
			pb=pb->link;
		}
		else                                              //当pa指数小 
		{
			pc=pc->insert(pa->coef,pa->exp);
			pa=pa->link;
		} 
	}
	
	if(pa!=nullptr) p1=pa;                               //处理多项式剩余的部分 
	else p1=pb;
	
	while(p1!=nullptr)
	{
		pc=pc->insert(p1->coef,p1->exp);
		p1=p1->link;
	}
	return C;
}


Polynomal Polynomal::Subtract(Polynomal& A,Polynomal& B)//相减 
{
	Data *pa,*pb,*pd,*p2;
	float temp;
	Polynomal D;  pd=D.first;
	pa=A.Gethead()->link;  pb=B.Gethead()->link;        //分别指向AB第一个节点
	
	while(pa!=nullptr && pb!=nullptr)
	{
		if(pa->exp > pb->exp)                           //当pb指数小
		{
			pd=pd->insert(-pb->coef,pb->exp);
			pb=pb->link;
		}
		else if(pa->exp == pb->exp)                     //当两者指数相等 
		{
			temp=pa->coef-pb->coef;
			if(temp != 0)
			{
				pd=pd->insert(temp,pa->exp);
			}
			pa=pa->link;
			pb=pb->link;
		}
		else                                            //当pa指数小
		{
			pd=pd->insert(pa->coef,pa->exp);
			pa=pa->link;
		}
	}                             
	
	while(pa!=nullptr)                                 //处理多项式剩余的部分 
	{
		pd=pd->insert(pa->coef,pa->exp);
		pa=pa->link;
	}
	while(pb!=nullptr)
	{
		pd=pd->insert(-pb->coef,pb->exp);
		pb=pb->link;
	}
	return D;
}
