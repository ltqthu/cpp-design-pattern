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

    virtual MobilePhoneBase* CreateMobilePhone() = 0;
};

// OPPO������
class OppoFactory
{
public:
    OppoFactory();
    ~OppoFactory();

    virtual MobilePhoneBase* CreateMobilePhone() override
    {
        return new OPPO();
    }
};



// VIVO������
class VivoFactory
{
public:
    VivoFactory();
    ~VivoFactory();

    virtual MobilePhoneBase* CreateMobilePhone() override
    {
        return new VIVO();
    }
};




int main()
{
    // ��һ��oppo����
    MobilePhoneFactory* oppo_factory = new OppoFactory();

    // oppo��������oppo�ֻ�
    MobilePhoneBase* oppo = oppo_factory->CreateMobilePhone();
    cout << "���ֻ�����Ϊ��" << oppo->Type() << endl;

    // ��һ��vivo����
    MobilePhoneBase* vivo_factory = new VivoFactory();

    // vivo��������vivo�ֻ�
    MobilePhoneBase* vivo = oppo_factory->CreateMobilePhone();
    cout << "���ֻ�����Ϊ��" << oppo->Type() << endl;

    // ����
    delete oppo;
    oppo = nullptr;
    delete oppo_factory;
    oppo_factory = nullptr;

    delete vivo;
    vivo = nullptr;
    delete oppo_factory;
    oppo_factory = nullptr;

    return 0;
}

