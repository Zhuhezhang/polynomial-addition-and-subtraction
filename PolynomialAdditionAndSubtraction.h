//�ṹ���Լ��������
#ifndef POLYNOMIALADDITIONANDSUBTRACTION_H_
#define POLYNOMIALADDITIONANDSUBTRACTION_H_

struct Data 
{
	float coef;//ϵ�� 
	int exp;   //ָ��
	Data* link;//ָ����һ���ڵ� 
	Data(float c,int e,Data* next=nullptr)
	{ 
		coef=c; exp=e; link=next;
	}
	Data* insert(float c,int e);              //�����½�� 
};

class Polynomal
{
public:
	Polynomal(){first=new Data(0,-1);}
    Data* Gethead() const {return first;}
    Polynomal Execute();                      //ִ�� 
    Polynomal Add(Polynomal&,Polynomal&);     //��� 
	Polynomal Subtract(Polynomal&,Polynomal&);//��� 
	
private:
	Data* first;
};
#endif
