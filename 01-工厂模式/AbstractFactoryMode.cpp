#include <iostream>
#include <string>
using namespace std;
/*
* �ؼ����룺��һ��������ۺ϶��ͬ���Ʒ��
* ���´����԰�ɫ�·��ͺ�ɫ�·�Ϊ������ɫ�·�Ϊһ����Ʒϵ�У���ɫ�·�Ϊһ����Ʒϵ�С���ɫ���´����ɫ���ӣ���ɫ���´����ɫ���֡�ÿ��ϵ�е��·���һ����Ӧ�Ĺ�������������һ�������������·��ܱ�֤�·�Ϊͬһ��ϵ�С�
*/

//����������
class Coat
{
public:
    virtual const string& GetType() = 0;
};

//��ɫ������
class BlackCoat : public Coat
{
public:
    BlackCoat() :Coat(), m_strType("Black Coat")
    {
    }

    const string& GetType() override
    {
        return m_strType;
    }
private:
    string m_strType;
};

//��ɫ������
class WhiteCoat : public Coat
{
public:
    WhiteCoat() :Coat(), m_strColor("White Coat")
    {
    }
    const string& GetType() override
    {
        return m_strColor;
    }

private:
    string m_strColor;
};

//���������
class Pants
{
public:
    virtual const string& color() = 0;
};

//��ɫ������
class BlackPants : public Pants
{
public:
    BlackPants() :Pants(), m_strColor("Black Pants")
    {
    }
    const string& color() override
    {
        return m_strColor;
    }

private:
    string m_strColor;
};

//��ɫ������
class WhitePants : public Pants
{
public:
    WhitePants() :Pants(), m_strColor("White Pants")
    {
    }
    const string& color() override
    {
        return m_strColor;
    }

private:
    string m_strColor;
};

//���󹤳���
class Factory
{
public:
    //���´����ӿڣ����س���������
    virtual Coat* CreateCoat() = 0;
    //���Ӵ����ӿڣ����س��������
    virtual Pants* CreatePants() = 0;
};

//������ɫ�·��Ĺ����࣬����ʵ�ִ�����ɫ���ºͰ�ɫ���ӵĽӿ�
class WhiteFactory : public Factory
{
public:
    Coat* CreateCoat() override
    {
        return new WhiteCoat();
    }

    Pants* CreatePants() override
    {
        return new WhitePants();
    }
};

//������ɫ�·��Ĺ����࣬����ʵ�ִ�����ɫ���ºͺ�ɫ���ӵĽӿ�
class BlackFactory : public Factory
{
    Coat* CreateCoat() override
    {
        return new BlackCoat();
    }

    Pants* CreatePants() override
    {
        return new BlackPants();
    }
};

int main()
{
    WhiteFactory* pWhiteFactory = new WhiteFactory;
    WhiteCoat* pWhiteCoat = pWhiteFactory->CreateCoat();
    cout << "��ɫ���µ����ͣ�" << pWhiteCoat->GetType() << endl;
    WhitePants* pWhitePants = pWhiteFactory->CreatePants();
    cout << "��ɫ���ӵ����ͣ�" << pWhitePants->GetType() << endl;

    BlackFactory* pBlackFactory = new BlackFactory;
    BlackCoat* pBlackCoat = pBlackFactory->CreateCoat();
    cout << "��ɫ���µ����ͣ�" << pBlackCoat->GetType() << endl;
    BlackPants* pBlackPants = pBlackFactory->CreatePants();
    cout << "��ɫ���ӵ����ͣ�" << pBlackPants->GetType() << endl;


    return 0;
}