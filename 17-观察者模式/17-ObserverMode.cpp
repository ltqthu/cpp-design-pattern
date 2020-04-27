#include <iostream>
#include <set>
using namespace std;

//�۲��߳�����
class Observer
{
public:
    virtual void ReceiveMessage(const string& strMessage) const = 0;
};

//���۲��߳�����
class Observed
{
public:
    virtual void AddObserver(Observer* pObserver) = 0;
    virtual void DeleteObserver(Observer* pObserver) = 0;
    virtual void SendMessage(const string& strMessage) const = 0;
};

//���۲���ʵ����
class Boss :public Observed
{
public:
    //��ӹ۲���
    void AddObserver(Observer* pObserver)
    {
        m_setObserver.insert(pObserver);
    }

    void DeleteObserver(Observer* pObserver)
    {
        m_setObserver.erase(pObserver);
    }

    //֪ͨ���й۲���
    void SendMessage(const string& strMessage) const
    {
        for (auto iter = m_setObserver.begin(); iter != m_setObserver.end(); ++iter)
        {
            (*iter)->ReceiveMessage(strMessage);
        }
    }

private:
    //��Ź۲��ߵ�����
    set<Observer*> m_setObserver;
};

//�۲���ʵ����
class Staff :public Observer
{
public:
    Staff(string strName) :m_strName(strName) {}

    //�յ�֪ͨ��ȡ�ʼ�����ʾ
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





