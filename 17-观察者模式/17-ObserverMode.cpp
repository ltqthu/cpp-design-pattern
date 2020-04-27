#include <iostream>
#include <set>
using namespace std;

//观察者抽象类
class Observer
{
public:
    virtual void ReceiveMessage(const string& strMessage) const = 0;
};

//被观察者抽象类
class Observed
{
public:
    virtual void AddObserver(Observer* pObserver) = 0;
    virtual void DeleteObserver(Observer* pObserver) = 0;
    virtual void SendMessage(const string& strMessage) const = 0;
};

//被观察者实现类
class Boss :public Observed
{
public:
    //添加观察者
    void AddObserver(Observer* pObserver)
    {
        m_setObserver.insert(pObserver);
    }

    void DeleteObserver(Observer* pObserver)
    {
        m_setObserver.erase(pObserver);
    }

    //通知所有观察者
    void SendMessage(const string& strMessage) const
    {
        for (auto iter = m_setObserver.begin(); iter != m_setObserver.end(); ++iter)
        {
            (*iter)->ReceiveMessage(strMessage);
        }
    }

private:
    //存放观察者的容器
    set<Observer*> m_setObserver;
};

//观察者实现类
class Staff :public Observer
{
public:
    Staff(string strName) :m_strName(strName) {}

    //收到通知，取邮件并显示
    void ReceiveMessage(const string& strMessage) const
    {
        cout << "Staff " << m_strName << " Receive Message:" << strMessage << endl;
    }

private:
    string m_strName;
};

int main()
{
    Observed* pBoss = new Boss();

    Observer* pStaffA = new Staff("StaffA");
    pBoss->AddObserver(pStaffA);
    Observer* pStaffB = new Staff("StaffB");
    pBoss->AddObserver(pStaffB);

    pBoss->SendMessage("test");

    delete pBoss;
    pBoss = nullptr;
    delete pStaffA;
    pStaffA = nullptr;
    delete pStaffB;
    pStaffB = nullptr;

    return 0;
}





