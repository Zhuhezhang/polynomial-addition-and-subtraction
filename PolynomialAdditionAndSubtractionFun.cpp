//���Ա������ʵ��
#include "PolynomialAdditionAndSubtraction.h"
#include <iostream>
#include <windows.h>
using namespace std;


Data* Data::insert(float c,int e)                                             //���ô˺�����thisָ��ָ�����ĺ���������� 
{
	link=new Data(c,e,link);
	return link;
}


Polynomal Polynomal::Execute()                                                //���岿�֣���������ʽ��ִ����Ӽ�����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);//�޸�������ɫ����windows.h�ж��� 
	cout<<"���������ʵ�ֶԶ���ʽ�ļӼ�����\n";
	cout<<"ע�⣺�������ʽʱҪ����ָ����С�������룡\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
	while(1)
	{
	    float coef;       int exp,i,z,y;
	    Data* A=nullptr;  Data* B=nullptr;
	    Polynomal Z;      A=Z.first;
	    Polynomal Y;      B=Y.first;
	
	    cout<<"���������ʽA��������";
	    cin>>z;
	    cout<<"�������������ʽA��ϵ����ָ����\n";
	    for(i=0;i<z;i++)
	    {
		    cin>>coef>>exp;
		    A=A->insert(coef,exp);
	    }
	
	    cout<<"���������ʽB��������";
	    cin>>y;
	    cout<<"�������������ʽB��ϵ����ָ����\n";
	    for(i=0;i<y;i++)
	    {
		    cin>>coef>>exp;
		    B=B->insert(coef,exp);
	    }

	    Polynomal X,W,V;
	    int flag1;
	    cout<<"��������Ҫִ�еĲ�����1.���ӷ� 2.����������";
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
		    	cout<<"����ָ����������룡";
			    cin>>flag1;
		    	continue;
		    }
	    }
	    
	    char flag2;
	    cout<<"�Ƿ��������(Y/N): ";
	    cin>>flag2;
	    if(flag2=='n'||flag2=='N')
	    {
	    	cout<<endl;
	    	cout<<"��лʹ�ã�\n";
	    	system("pause");
	    	break;
		}
    }
}


Polynomal Polynomal::Add(Polynomal& A,Polynomal& B)        //��� 
{
	Data *pa,*pb,*pc,*p1;
	float temp;
	Polynomal C;  pc=C.first;
	pa=A.Gethead()->link;  pb=B.Gethead()->link;           //�ֱ�ָ��AB��һ���ڵ�
	
	while(pa!=nullptr && pb!=nullptr)
	{
		if(pa->exp > pb->exp)                              //��pbָ��С 
		{
			pc=pc->insert(pb->coef,pb->exp);
			pb=pb->link;
		}
		else if(pa->exp == pb->exp)                       //������ָ����� 
		{
			temp=pa->coef+pb->coef;
			if(temp != 0)
			{
				pc=pc->insert(temp,pa->exp);
			}
			pa=pa->link;
			pb=pb->link;
		}
		else                                              //��paָ��С 
		{
			pc=pc->insert(pa->coef,pa->exp);
			pa=pa->link;
		} 
	}
	
	if(pa!=nullptr) p1=pa;                               //�������ʽʣ��Ĳ��� 
	else p1=pb;
	
	while(p1!=nullptr)
	{
		pc=pc->insert(p1->coef,p1->exp);
		p1=p1->link;
	}
	return C;
}


Polynomal Polynomal::Subtract(Polynomal& A,Polynomal& B)//��� 
{
	Data *pa,*pb,*pd,*p2;
	float temp;
	Polynomal D;  pd=D.first;
	pa=A.Gethead()->link;  pb=B.Gethead()->link;        //�ֱ�ָ��AB��һ���ڵ�
	
	while(pa!=nullptr && pb!=nullptr)
	{
		if(pa->exp > pb->exp)                           //��pbָ��С
		{
			pd=pd->insert(-pb->coef,pb->exp);
			pb=pb->link;
		}
		else if(pa->exp == pb->exp)                     //������ָ����� 
		{
			temp=pa->coef-pb->coef;
			if(temp != 0)
			{
				pd=pd->insert(temp,pa->exp);
			}
			pa=pa->link;
			pb=pb->link;
		}
		else                                            //��paָ��С
		{
			pd=pd->insert(pa->coef,pa->exp);
			pa=pa->link;
		}
	}                             
	
	while(pa!=nullptr)                                 //�������ʽʣ��Ĳ��� 
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
