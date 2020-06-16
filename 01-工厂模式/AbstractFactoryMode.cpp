#include <iostream>
#include <string>
using namespace std;
/*
* 关键代码：在一个工厂里聚合多个同类产品。
* 以下代码以白色衣服和黑色衣服为例，白色衣服为一个产品系列，黑色衣服为一个产品系列。白色上衣搭配白色裤子，黑色上衣搭配黑色裤字。每个系列的衣服由一个对应的工厂创建，这样一个工厂创建的衣服能保证衣服为同一个系列。
*/

//抽象上衣类
class Coat
{
public:
    virtual const string& GetType() = 0;
};

//黑色上衣类
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

//白色上衣类
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

//抽象裤子类
class Pants
{
public:
    virtual const string& color() = 0;
};

//黑色裤子类
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

//白色裤子类
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

//抽象工厂类
class Factory
{
public:
    //上衣创建接口，返回抽象上衣类
    virtual Coat* CreateCoat() = 0;
    //裤子创建接口，返回抽象裤子类
    virtual Pants* CreatePants() = 0;
};

//创建白色衣服的工厂类，具体实现创建白色上衣和白色裤子的接口
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

//创建黑色衣服的工厂类，具体实现创建黑色上衣和黑色裤子的接口
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
    cout << "白色上衣的类型：" << pWhiteCoat->GetType() << endl;
    WhitePants* pWhitePants = pWhiteFactory->CreatePants();
    cout << "白色裤子的类型：" << pWhitePants->GetType() << endl;

    BlackFactory* pBlackFactory = new BlackFactory;
    BlackCoat* pBlackCoat = pBlackFactory->CreateCoat();
    cout << "黑色上衣的类型：" << pBlackCoat->GetType() << endl;
    BlackPants* pBlackPants = pBlackFactory->CreatePants();
    cout << "黑色裤子的类型：" << pBlackPants->GetType() << endl;


    return 0;
}