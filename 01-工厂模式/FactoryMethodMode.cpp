#include <iostream>
using namespace std;

enum MobilePhoneType
{
    TYPE_OPPO,
    TYPE_VIVO
};

// 手机抽象类
class MobilePhoneBase
{
public:
    MobilePhoneBase() {};
    ~MobilePhoneBase() {};

    virtual const string& Type() = 0; // 纯虚函数
};

// OPPO子类
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
    string m_strBrand; // 品牌名称
};


// VIVO子类
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
    string m_strBrand; // 品牌名称
};


// 手机工厂类
class MobilePhoneFactory
{
public:
    MobilePhoneFactory() {};
    ~MobilePhoneFactory() {};

    virtual MobilePhoneBase* CreateMobilePhone() = 0;
};

// OPPO工厂类
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



// VIVO工厂类
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
    // 建一个oppo工厂
    MobilePhoneFactory* oppo_factory = new OppoFactory();

    // oppo工厂生产oppo手机
    MobilePhoneBase* oppo = oppo_factory->CreateMobilePhone();
    cout << "该手机类型为：" << oppo->Type() << endl;

    // 建一个vivo工厂
    MobilePhoneBase* vivo_factory = new VivoFactory();

    // vivo工厂生产vivo手机
    MobilePhoneBase* vivo = oppo_factory->CreateMobilePhone();
    cout << "该手机类型为：" << oppo->Type() << endl;

    // 清理
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

