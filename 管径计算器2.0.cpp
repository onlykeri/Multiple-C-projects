#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>	//isdigit(),isalpha()��ͷ�ļ�
#define PI 3.1415926 //����PI

using namespace std;
int remember1,remember2;
double x,u,Q,P,Result,deviation=0.001,l2;
char choice1,choice2,choice3,choice4;
double l=0.25;

void FirstChoice();	//�ж��Ƿ���Ĺ��ӳ���
void SecondChoice();	//�ж��������ǹ���ֱ�����ǰ뾶
void ThirdChoice();	//�ж��������ĵ�λ
void FourthChoice();	//�жϳ����Ƿ����
void FifthChoice();
void Import();		//���������ֵ
void OutputResult();
double Judge(double);	// �жϺϷ���

int main()
{
	system("color f0");	//�޸ĳ���������ڵı�����ɫ��ǰ����ɫ��Ĭ��Ϊ������ɫ����f���ͺ�ɫ����0��
	cout << endl;
	cout << "*����" << endl;	//����Ϊ��x=[(128*u*l*Q)/(PI*P)]1/4
	FirstChoice();
	cout << endl;
	SecondChoice();
	cout << endl;
	ThirdChoice();
	cout << endl;
	FifthChoice();
	there:
	Import();
	Result = sqrt(sqrt((128*u*l*Q)/(PI*P)));	//������
	cout << endl;
	OutputResult();
	cout << endl;
	FourthChoice();
	goto there;

	return 0;
}

void FirstChoice()	//�ж��Ƿ���Ĺ��ӳ���
{
	cout << "#Ĭ�Ϲ��ӳ���Ϊ25cm����ѡ���Ƿ���Ҫ���Ĺ��ӳ��ȣ�y/n��:" << endl;
	cin >> choice1;
	switch(choice1)
	{
	case 'y': case 'Y':
		cout << "��������ĺ�ĳ��ȣ���λ��cm�����ף�" << endl;
//		cin >> l2;
		Judge(l2);
		l = l2;
		break;
	case 'n': case 'N':
		break;
	default:
		cout << "*������ķǷ���Ĭ�Ϲ��ӳ���Ϊ25cm*" << endl;
		break;
	}
}

void SecondChoice()	//�ж���������ֱ�����ǰ뾶
{
	cout << "#Ĭ��������Ϊ����ֱ�������������Ӻ�ȣ�����ѡ���Ƿ����Ϊ�뾶��y/n��" << endl;	//��ѡ��������Ϊ�뾶��0������ֱ����1���������ѡ����Ϊ�뾶������0����������1��
	cin >> choice2;	//�ж�������Ϊ�뾶����ֱ��
	switch(choice2)
	{
		case 'y': case 'Y':
		remember1 = 0;
		cout << "*������Ϊ���ڰ뾶*" << endl;
		break;
		case 'n': case 'N':
		remember1 = 1;
		cout << "*������Ϊ����ֱ��*" << endl;
		break;
		default:
			cout << "*������ķǷ���Ĭ��������Ϊֱ��*" << endl;
		remember1 = 1;
		break;

	}
	//	cout << "��������ӳ��ȣ�����λ��m���ף�" << endl;
//	cin >> l;
//	if(l<0)
//	{
//		cout << "@������Ĺ��ӳ��ȷǷ������ӳ���Ӧ��Ϊ������" << endl;
//		cout << "@���������룡" << endl;
//		goto there;
////    		exit(0);
//	}
}

void ThirdChoice()	//�ж��������ĵ�λ
{
	cout << "#Ĭ���������ĵ�λΪ���ף�mm������ѡ���Ƿ������������λΪ�ף�m����y/n��" << endl;	//��ѡ���������ĵ�λ�ף�0�����ߺ��ף�1���������ѡ��λ������0����������1��
	cin >> choice3;	//�ж�������Ϊ
	switch(choice3)
	{
		case 'y': case 'Y':
			remember2 = 0;
			cout << "*֮���������ĵ�λ����*" << endl;
		break;
		case 'n': case 'N':
			remember2 = 1;
			cout << "*֮���������ĵ�λ�Ǻ���*" << endl;
		break;
		default:
			cout << "*�������ַ��Ƿ���Ĭ���������ĵ�λΪ����*" << endl;
		remember2 = 1;
		break;

	}
}

void FourthChoice()	//�ж��Ƿ��������
{
	cout << "#�����Ƿ�������㣺(y/n)" << endl;
	cin >> choice4;
	switch(choice4)	//�ж��Ƿ��������
	{
		case 'y':case 'Y':
			break;
		case 'n':case 'N':
			exit(0);
		default:
			exit(0);
	}
}

void FifthChoice()	// ƫ��
{
	cout << "������ƫ��ֵ������λ�����ף�" << endl;
	cout << "�����磺���ӹ��18F�ı�׼Ҫ�󣨹���ֱ��6���ף��������ܱڣ���ƫ��ֵΪ0.1���ף�������ý����5.9~6.1��Χ�ڶ�������Ҫ��" << endl;
	cin >> deviation;
	deviation = deviation*0.001;	//ƫ����׵�λת��Ϊ��
}

void Import()	//���������ֵ
{


	cout << endl;
	cout << "****************************************************************" << endl;
	there2:
	cout << "������ճ��ϵ�������磺1.0*10^3������e����10��д��1.0e3�������·���ͬ������ֵ������Ҳ�ɲ��ô˷���������λ��Pas�����룩��" << endl;
	cin >> u;
	if(u<0)
	{
		cout << "@�������ճ��ϵ���Ƿ���ճ��ϵ��Ӧ��Ϊ������" << endl;
		cout << "@���������룡" << endl;
		goto there2;
	//    	exit(0);
	}
	cout << "������ѹǿ�����λ��Pa������" << endl;
	cin >> P;
	P=abs(P);
	there3:
	cout << "�������������������λ��m^3/s,������/s��" << endl;
	cin >> Q;
	if(Q<0)
	{
		cout << "@���������������Ƿ����������Ӧ��Ϊ������" << endl;
		cout << "@���������룡" << endl;
		goto there3;
//    		exit(0);
	}
}

void OutputResult()	//������
{
	  if(Result >( 0.006-deviation) && Result < (0.006-deviation))
	    {
		cout << "*����õĹ���ֱ������Ҫ��" <<endl;
	    }else
	    {
		cout << "*����õĹ���ֱ��������Ҫ��" <<endl;
	    }
	    if(remember1 == 0 && remember2 == 0)	//�뾶����λ��
	   {
		Result = Result/2;
		cout << "���Ϊ��" << endl;
		cout << "*���ӵ��ڰ뾶�ǣ� "
		     << Result << "��" << endl;
	   }else if(remember1 == 0 && remember2 == 1)	//�뾶����λ����
	   {
		Result = Result/2;
		cout << "���Ϊ��" << endl;
		cout << "*���ӵ��ڰ뾶�ǣ� "
		     << Result*1000 << "����" << endl;
	   }else if(remember1 == 1 && remember2 == 0)	//ֱ������λ��
	   {
		Result = Result;
		cout << "���Ϊ��" << endl;
		cout << "*���ӵ���ֱ���ǣ� "
		     << Result << "��" << endl;
	   }else if(remember1 == 1 && remember2 == 1 )	//ֱ������λ����
	   {
		Result = Result;
		cout << "���Ϊ��" << endl;
		cout << "*���ӵ���ֱ���ǣ� "
		     << Result*1000 << "����" << endl;
	   }
}

double Judge(double num)	// �ж��������ֵĺϷ���
{

	cin >> num;
	if(isalpha(num))	// ����ĸ�򷵻�1��ִ���������
	{
		cout << "����������Ƿ������������룺";
		cin.clear();	//	���std::cin�Ĵ���״̬
		cin.sync();	// 	������뻺����
		Judge(num);
	}
	return num;

}
