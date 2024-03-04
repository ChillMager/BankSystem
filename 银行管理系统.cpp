#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
#include<strstream>
#include<conio.h>
using namespace std;
class Function;
class User
{
public:
    void get( );
    friend class Function;
    void print();
    void PassWord();
    void SaveFile(User &);
    vector<string> StrFunction;
    User(){}
    User(int A,string N,int F,string I,string Ad,int T):Accout(A),Name(N),Fmoney(F),ID(I),Address(Ad),Telephone(T){}
private:
  int Accout;//�˺�
  string Name;//����
  int Fmoney;
  string ID;
  string Address;
  int Telephone;
  char  Pword1[9];
  char Pword2[9];
};
class Function
{
public:
    void Saving(User &);
    void Drawing(User &);
    void Balance(User &);
    void Record(User &);
private:
    int  SaveAndDrawMoney;
 
 
};
void Function::Saving(User &u)
{
 system("cls");
 cout<<"\n\n\n\t\t*********************************************\n"<<endl;
 cout<<"\t\t���������";
 string str1("�ִ� RMB  �� +   ");
 cin>>SaveAndDrawMoney;
 u.Fmoney+=SaveAndDrawMoney;
 strstream ss;//��������ַ�����
 string  str2;
 ss<<SaveAndDrawMoney;
 ss>>str2;
 str1=str1+str2;
 u.StrFunction.push_back(str1);
 cout<<"\n\n\t\t�����ɹ��������κμ��������˵���";
 getch();
}
void Function::Drawing(User &u)
{
  system("cls");
  cout<<"\n\n\n\t\t*********************************************\n"<<endl;
  cout<<"\t\t������ȡ���";
  string str("��ȡ RMB  �� -   ");
  int k=0;
  while(k<=3)
  {
      int Money;
    cin>>SaveAndDrawMoney;
    Money=u.Fmoney -SaveAndDrawMoney;
   if(Money>=0)
  {
     system("cls");
    cout<<"\n\n\n\t\t���ڳ��������Եȣ�"<<endl;
    strstream ss;
    string  str2;
    ss<<SaveAndDrawMoney;
    ss>>str2;
    str=str+str2;
    u.StrFunction.push_back(str);
    break;
  }
  else
  {
      k++;
      if(k>=3)
      {
      system("cls");
      cerr<<"\n\n\n\t\t�ܱ�Ǹ�����ظ����������"<<endl
            <<"\n\t\t�����˿��С���"<<endl;
      exit(0);
      }
      system("cls");
      cerr<<"\n\n\n\t\t�Բ���������Ľ�����Ч��"<<endl
          <<"\n\t\t       ����������:  ";
  }
  }
  cout<<"\n\n\t\t�����ɹ��������κμ��������˵���";
  getch();
}
void Function::Balance(User &u)
{
  system("cls");
  cout<<"\n\n\n\t\t*********************************************\n"<<endl;
  cout<<"\t\t�㵱ǰ������ǣ�";
  cout<<"\t\t"<<u.Fmoney<<endl;
  cout<<"\n\t\t*********************************************\n"<<endl;
  cout<<"\n\t\t�����ɹ��������κμ��������˵���";
  getch();
}
void Function::Record(User &u)
{
    system("cls");
    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
    cout<<"\t\tժҪ ���� ���� ��/ȡ����"<<endl;
    vector<string>::iterator  iter,iend;
    iter=u.StrFunction.begin();
    for(iter;iter!=u.StrFunction.end();iter++)
        cout<<"\n\t\t"<<*iter<<endl;
    cout<<"\n\t\t*********************************************\n"<<endl;
    cout<<"\n\t\t�����ɹ��������κμ��������˵���";
    getch();
}
void User::print() //mark
{
    system("cls");
 cout<<"\n\n\n\t\t*********************************************\n"<<endl;
 cout<<"\n\t\t�û����ţ� "<<Accout<<endl;
 cout<<"\n\t\t������     "<<Name <<endl;
 cout<<"\n\t\t������ "<<Fmoney<<endl;
 cout<<"\n\t\t���֤�ţ� "<<ID<<endl;
 cout<<"\n\t\t��ַ��     "<<Address <<endl;
 cout<<"\n\t\t��ϵ�绰�� "<<Telephone <<endl;
 cout<<"\n\t\t���룺     "<<Pword1<<endl;
 cout<<"\n\t\t*********************************************\n"<<endl;
 cout<<"\n\t\t�����ɹ��������κμ��������˵���";
 getch();
 return ;
}
void User::SaveFile(User &u)
{
    ofstream outfile("outfile.txt", ios::trunc );//trunc����ļ����ھʹ򿪲����������,�粻���ھͽ������ļ�
    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
   outfile<<"\t\t�û����ţ� "<<Accout<<endl
             <<"\t\t������ "<<Name<<endl
             <<"\t\t������ "<<Fmoney<<endl
             <<"\t\t���֤�ţ� "<<ID<<endl
             <<"\t\t��ַ�� "<<Address<<endl
             <<"\t\t��ϵ�绰�� "<<Telephone<<endl
             <<"\t\t���룺 "<<Pword1<<endl;
   cout<<"\n\t\t*********************************************\n"<<endl;
   outfile.close();
}
void User::PassWord()
{
   int num=0;
 while(num<3)
 {
  cout<<"\n\t\t������8λ�������룺";
 for(int i=0;i<8;i++)
 { Pword1[i]=getch();cout<<"*";}
   Pword1[8]='\0';
   cout<<endl;
   cout<<"\n\t\t����һ��ȷ�����룺";
   for(int j=0;j<8;j++)
   { Pword2[j]=getch();cout<<"*";}
   cout<<endl;
   Pword2[8]='\0';
 if(strcmp(Pword1,Pword2)==0)
 {
     cout<<"\n\n\t\t����ȷ�ϳɹ��������κμ��������˵�";
    getch();
    return ;
 }
 else
 {
     num++;
     cout<<"\n\t\t�����������������������룡\n"<<endl;
 }
 if(num==3)
 {
     system("cls");
     cerr<<"\n\n\n\t\t�Բ������������벻��ȷ\n"<<endl
            <<"\t\t��л���ʹ�ã��ټ���    "<<endl;
     exit(0);
 }
 }
}
void User::get()
{
    system("cls");
   cout<<"\n\n\n\t\t�������û���Ϣ��\n"<<endl;
   cout<<"\t\t*********************************************\n"<<endl;
   cout<<"\n\t\t���ţ�";
   cin>>Accout;
   cout<<"\n\t\t������";
   cin>>Name;
   cout<<"\n\t\t������";
   cin>>Fmoney;
   cout<<"\n\t\t���֤�ţ�";
   cin>>ID;
   cout<<"\n\t\t��ַ��";
   cin>>Address;
   cout<<"\n\t\t��ϵ�绰��";
   cin>>Telephone;
   PassWord();
   cout<<"\n\t\t*********************************************\n"<<endl;
}
void Sign()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\tлл��ʹ�����й���ϵͳ \t \n\n"<<endl;
    cout<<"\t\t*********************************************\n"<<endl;
    cout<<"\t\t         ����: ���    \n\n"
           <<"\t\t         �༶: �����201��\n\n"
           <<"\t\t         ѧ��: 2202004166\n\n"<<endl;
     cout<<"\n\t\t         �Ѿ��ɹ��˳�"<<endl
            <<"\n\t\t         ��ӭ��Ĺ��٣�" <<endl;
}
char custom(User &u)
{
      char x;
    system("cls");
cout<<"\n\n\n\t\t������������������������������������������������������\n"
        <<"\t\t��                                                   ��\n"
        <<"\t\t��            ��ӭʹ�ô������ϵͳ                   ��\n"
        <<"\t\t��                                                   ��\n"
        <<"\t\t��                                                   ��\n"
        <<"\t\t��            ���û���ʹ��ǰѡ�񿪻���               ��\n"
        <<"\t\t��                                                   ��\n"
        <<"\t\t��            ��ѡ��                               ��\n"
        <<"\t\t��                ������1��ѡ�񿪻�                  ��\n"
        <<"\t\t��                �����������˳�                     ��\n"
        <<"\t\t��                                                   ��\n"
        <<"\t\t��                                                   ��\n"
        <<"\t\t������������������������������������������������������\n"<<endl;
         cout<<"\n\t\t��ѡ�������ʽ�� ";
         cin>>x;
         if(x=='1')
         {
            u.get();
         }
         else
         {
             Sign();
             exit(0);
         }
         return 0;
}
char menu()
{
  int k=0;
  char a[3],c,i;
    system("cls");
    cout<<"\n\n\n\t\t                ���˵�          \n\n" ;
    cout<<"\t\t*********************************************\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*     ������ʽ:                             *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*             1.���       2.ȡ��           *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*             3.��ѯ���   4.��ѯ��ʷ��¼   *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*             5.�û���Ϣ   6.���沢�˳�     *\n"
        <<"\t\t*********************************************\n"<<endl;
        while(k<3)
        {
            cout<<"\n\t\t��ѡ�������ʽ:  ";
        cin>>a;
        if(strlen(a)==1)
        {
            for(i='1';i<='6';i++)
            {  c=i;
            if(c==a[0]) return c;
            }
        }
        else
        {
            system("cls");
        cerr<<"\n\n\n\t\t\t��������!\n"<<endl
              <<"\t\t\t���������룺 "<<endl;
        k++;
        }
        while(k>=3)
        {
            system("cls");
          cerr<<"\n\n\n\t\t�Բ������������벻��ȷ\n"<<endl
             <<"\n\t\t��л���ʹ�ã��ټ���\n"<<endl;
            exit(0);
        }
        }
        return c;
    }
char Choose(  User &u,Function &F)
{
  char c=menu();
  while(c!='6')
  {
      switch(c)
  {
  case '1': F.Saving(u);c=menu();break;
  case '2':F.Drawing(u);c=menu();break;
  case '3':F.Balance(u);c=menu();break;
  case '4':F.Record(u);c=menu();break;
  case '5':u.print();c=menu();break;
  }
 
 
  }
  u.SaveFile(u);
  Sign();
  return 0;
}
int main()
{
  User u;//�û���
  Function F;
  vector<Function> FunctionUser;
  custom(u);
  Choose(u,F);
}
