#include <iostream>
using namespace std;


enum MobilePhoneType
{
    TYPE_OPPO,
    TYPE_VIVO
};

// �ֻ�������
class MobilePhoneBase
{
public:
    MobilePhoneBase() {};
    ~MobilePhoneBase() {};

    virtual const string& Type() = 0; // ���麯��
};

// OPPO����
class OPPO : public MobilePhoneBase
{
public:
    OPPO() :MobilePhoneBase(), m_strBrand("OPPO") {}
    ~OPPO() {};

    virtual const string& Type() override
    {
        return m_strBrand;
    }

private:
    string m_strBrand; // Ʒ������
};


// VIVO����
class VIVO : public MobilePhoneBase
{
public:
    VIVO() :MobilePhoneBase(), m_strBrand("VIVO") {}
    ~VIVO() {};

    virtual const string& Type() override
    {
        return m_strBrand;
    }
private:
    string m_strBrand; // Ʒ������
};


// �ֻ�������
class MobilePhoneFactory
{
public:
    MobilePhoneFactory() {};
    ~MobilePhoneFactory() {};

    MobilePhoneBase* CreateMobilePhone(MobilePhoneType type)
    {
        switch (type)
        {
        case TYPE_OPPO:
            return new OPPO();
        case TYPE_VIVO:
            return new VIVO();
        default:
            break;
        }
        return nullptr;
    }

private:

};


int main()
{
    // ��һ���ֻ�����
    MobilePhoneFactory* factory = new MobilePhoneFactory();
    // �ֻ��������ݲ�ͬ����������ͬ�ֻ�
    MobilePhoneBase* oppo = factory->CreateMobilePhone(TYPE_OPPO);
    cout << "���ֻ�����Ϊ��" << oppo->Type() << endl;

    MobilePhoneBase* vivo = factory->CreateMobilePhone(TYPE_VIVO);
    cout << "���ֻ�����Ϊ��" << oppo->Type() << endl;

    // ����
    delete oppo;
    oppo = nullptr;
    delete vivo;
    vivo = nullptr;
    delete factory;
    factory = nullptr;

    return 0;
}

