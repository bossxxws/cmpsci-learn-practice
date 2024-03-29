#include <iostream>
using namespace std;
#include<string>
#define Max 1000
//������ϵ�˽ṹ��
struct person
{
	string Name;
	string Sex;
	int Age;
	string Phone;
	string Address;

};
struct Addressbook {
	struct person personArry[Max]; 
	int Size;
};
//��ʾ�˵�
void showMenu() 
{
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}
//�����ϵ��
void Addperson(Addressbook * Black) //Blackָ�����Addressbook�еĶ���
{
	if (Black->Size == Max) 
	{	
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else 
	{
		string name;
		cout << "����������:  " << endl;
		cin >> name;
		Black->personArry[Black->Size].Name = name; 
		cout << "�������Ա�: " << endl;
		cout << "����------��  " << endl;
		cout << "����------Ů  " << endl;
		string sex;
		while (true)
		{
			cin >> sex;
			if (sex == "��" || sex == "Ů" )
			{
				Black->personArry[Black->Size].Sex = sex;
				break;
			}
		}
		cout << "���������䣺" << endl;
		int age;
		cin>> age;
		Black->personArry[Black->Size].Age = age;
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		Black->personArry[Black->Size].Phone = phone;
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		Black->personArry[Black->Size].Address = address;
		Black->Size++;//����ͨѶ¼�е�����
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");			
	}
	
}
//��ʾ��ϵ��
void showPerson(Addressbook * Black) 
{
	//�ж�ͨѶ¼��û����
	if(Black->Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;

	}
	else 
	{
		for (int i = 0; i < Black->Size; i++) 
		{
			cout << "  ����  ��"     <<Black->personArry[i].Name << "\t";
			cout << "  �Ա�  ��"     << Black->personArry[i].Sex << "\t";
			cout << "  ����  ��"     << Black->personArry[i].Age << "\t";
			cout << "  �绰  ��"     << Black->personArry[i].Phone << "\t";
			cout << "��ͥסַ��" << Black->personArry[i].Address << endl;
		}
	}
	system("pause");
	system("cls");//�����Ļ
}
//ɾ����ϵ��-�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�˾���λ�ã������ڷ���-1
//�����ϵ���Ƿ����
int isExist(Addressbook * Black,string cinname) //����ʱ��Ӧ�ô���ָ�� Addressbook �ṹ���ָ����Ϊ�����������ǽ�����֮��Ķ���
{
	for (int i = 0; i < Black->Size; i++) 
	{
		if (Black->personArry[i].Name == cinname) 
		{
			return i;
		}
	}
	return -1;

}
//ɾ����ϵ��
void deletePerson(Addressbook * Black)
{
	cout << "������Ҫɾ������ϵ�˵�����" << endl;
	string cinname;
	cin >> cinname;
	int ret = isExist(Black, cinname);
	if (ret != -1) 
	{
		for (int i = ret; i < Black->Size; i++) 
		{
			//����ǰ��
			Black->personArry[i] = Black->personArry[i + 1];
		}
		Black->Size--;//����ͨѶ¼������
		cout << "ɾ����ϵ�ˣ� " << cinname << " �ɹ�" << endl;
	}
	else 
	{
		cout << "���޴��� " << endl;
	}
	system("pause");
	system("cls");//�����Ļ
}
//����ָ����ϵ��
void findPerson(Addressbook * Black) 
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(Black,name);
	if (ret != -1)
	{
		cout << "�ҵ���ϵ�ˣ�" << endl;
		cout << "     ������" << Black->personArry[ret].Name << "\t";
		cout << "     �Ա�" << Black->personArry[ret].Sex  << "\t";
		cout << "     ���䣺" << Black->personArry[ret].Name << "\t";
		cout << "     �绰��" << Black->personArry[ret].Phone << "\t";
		cout << "     ��ͥסַ��" << Black->personArry[ret].Address << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");	
}
//�޸���ϵ��
void modifyPerson(Addressbook* Black) 
{
	cout << "Please input the name:" << endl;
	string name;
	cin >> name;
	int ret = isExist(Black, name);
	if (ret != -1)
	{
		string Newname;
		cout << "Please input the Newname:";
		cin >> Newname;
		string NewSex;
		cout << "Please input the NewnSex:";
		cin >> NewSex;
		int NewAge;
		cout << "Please input the NewAge:";
		cin >> NewAge;
		cout << "Please input the NewPhone:";
		string NewPhone;
		cin >> NewPhone;
		cout << "Please input the NewAddress:";
		string NewAddress;
		cin >> NewAddress;
		Black->personArry[ret].Name = Newname;
		Black->personArry[ret].Sex = NewSex;
		Black->personArry[ret].Age = NewAge;
		Black->personArry[ret].Phone = NewPhone;
		Black->personArry[ret].Address = NewAddress;
		cout << "---------�ѳɹ��޸���ϵ��---------" << endl;
		cout << "-------------��ǰ��Ϣ-------------" << endl;
		cout << "       ������" <<  Newname << "\t";
		cout << "       �Ա�" <<  NewSex << "\t";
		cout << "       ���䣺" <<  NewAge << "\t";
		cout << "       �绰��" <<  NewPhone << "\t";
		cout << "       ��ͥסַ��" << NewAddress << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void CleanAll(Addressbook* Black) 
{
	string s;
	cout << "��ȷ�����������ϵ�������루Yes/No��" << endl;
	cin >> s;
	if (s ==  "Yes") 
	{
		Black->Size = 0;
		cout << "----------������ϵ�������----------" << endl;

	}
	system("pause");
	system("cls");
}

//�˵��ĵ���
int main()
{	
	int select = 0;//�����û�ѡ������ı���	
	Addressbook Black;
	Black.Size = 0;
	while (true) 
	{	
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			Addperson(&Black);//ֻдBlack��ֵ���ݣ�Ҫд��ַ������������
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&Black);
			break;
		case 3://3��ɾ����ϵ��
			deletePerson(&Black);
			break;
		case 4://4��������ϵ��
			findPerson(&Black);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&Black);
			break;
		case 6://6�������ϵ��
			CleanAll(&Black);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}	
	}
	system("pause");
	return 0;
}
//���ݶ���ĵ�ַ��&Black����
//��������������Ӧ����ָ�� Addressbook �����ָ�루Addressbook* �����߸�ͨ�õ�ָ�����ͣ��� void* ����
//ͨ��ָ�����ֱ���޸� Addressbook ��������ݡ�
//���Ա��������������п�������ʡ�ڴ��ʱ�䡣
//�ں����ڲ��Զ�������޸ĺ󣬵����߽���������ĸ��ģ���Ϊ�������õ���ͬһ������
//���ݶ�����Black����
//��������������Ӧ���� Addressbook �������ͣ�Addressbook����
//�ں����ڲ��Զ�������޸�ʱ��ʵ�����ǶԴ������ĸ������в���������Ӱ��ԭʼ����
//���ܻ����������ڴ濪�����ر��ǵ�����ϴ�ʱ����Ϊ��Ҫ���ж���Ŀ�����
//������޸Ľ��ں����ڲ��ɼ��������߿����Ķ�����Ȼ��ԭʼ�ġ�δ�޸ĵĶ���


