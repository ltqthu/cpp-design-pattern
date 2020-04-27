#include <iostream>
using namespace std;


enum MobilePhoneType
{
    TYPE_OPPO,
    TYPE_VIVO
};

// �ֻ�����
class MobilePhoneBase
{
public:
    MobilePhoneBase() {};
    ~MobilePhoneBase() {};

    virtual void Create() = 0; // ���麯��
private:

};

// OPPO����
class OPPO : public MobilePhoneBase
{
public:
    OPPO() :MobilePhoneBase() {};
    ~OPPO() {};

    virtual void Create() override; // virtual, override���п���

private:

};


void OPPO::Create()
{
    cout << "Create OPPO Mobile Phone" << endl;
}

// VIVO����
class VIVO : public MobilePhoneBase
{
public:
    VIVO() :MobilePhoneBase() {};
    ~VIVO() {};

    virtual void Create() override;
private:

};


void VIVO::Create()
{
    cout << "Create VIVO Mobile Phone" << endl;
}


// �ֻ�������
class MobilePhoneFactory
{
public:
    MobilePhoneFactory() {};
    ~MobilePhoneFactory() {};

    MobilePhoneBase* CreateMobilePhone(MobilePhoneType type);

private:

};


MobilePhoneBase* MobilePhoneFactory::CreateMobilePhone(MobilePhoneType type)
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

int main()
{
    MobilePhoneFactory* factory = new MobilePhoneFactory();

    MobilePhoneBase* oppo = factory->CreateMobilePhone(TYPE_OPPO);
    oppo->Create();
    MobilePhoneBase* vivo = factory->CreateMobilePhone(TYPE_VIVO);
    vivo->Create();

    delete oppo;
    oppo = nullptr;
    delete vivo;
    vivo = nullptr;
    delete factory;
    factory = nullptr;

    return 0;
}

