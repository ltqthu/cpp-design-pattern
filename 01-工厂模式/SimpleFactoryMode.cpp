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
    // 建一个手机工厂
    MobilePhoneFactory* factory = new MobilePhoneFactory();
    // 手机工厂根据不同类型生产不同手机
    MobilePhoneBase* oppo = factory->CreateMobilePhone(TYPE_OPPO);
    cout << "该手机类型为：" << oppo->Type() << endl;

    MobilePhoneBase* vivo = factory->CreateMobilePhone(TYPE_VIVO);
    cout << "该手机类型为：" << oppo->Type() << endl;

    // 清理
    delete oppo;
    oppo = nullptr;
    delete vivo;
    vivo = nullptr;
    delete factory;
    factory = nullptr;

    return 0;
}

