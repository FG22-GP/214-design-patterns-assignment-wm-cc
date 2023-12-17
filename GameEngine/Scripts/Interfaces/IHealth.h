#pragma once
#include <list>

#include "IObserver.h"


class IHealth
{
public:

    virtual ~IHealth() = default;
    virtual void TakeDamage(int DamageTaken);
    virtual void GainHealth(int HealthGained);
    int GetCurrentHealth();
    bool GetIsDead();
    void AddObserver(IObserver* observer);
    void RemoveObserver(IObserver* observer);
    void OnDeathNotify();
    void OnHealthChangeNotify();

protected:
    int MaxHealth = 10;
    int CurrentHealth = 10;
    bool bIsDead = false;
    std::list<IObserver*> ObserverList; // list of observers to notify 
};

 inline void IHealth::TakeDamage(int damageTaken)
 {
     if (bIsDead) return;
     
     CurrentHealth -= damageTaken;
     OnHealthChangeNotify();
     if (CurrentHealth <= 0)
     {
         OnDeathNotify();
         bIsDead = true;
     }
 }

inline void IHealth::GainHealth(int HealthGained)
{
    if (bIsDead || CurrentHealth >= MaxHealth) return;

    CurrentHealth += HealthGained;
     
     OnHealthChangeNotify();

    if (CurrentHealth + HealthGained > MaxHealth) 
    {
        CurrentHealth = MaxHealth;
    }
}

inline int IHealth::GetCurrentHealth()
{
    return CurrentHealth;
}

inline bool IHealth::GetIsDead()
{
    return bIsDead;
}

inline void IHealth::AddObserver(IObserver* observer)
{
    ObserverList.push_back(observer);
}

inline void IHealth::RemoveObserver(IObserver* observer)
{
    
}

inline void IHealth::OnDeathNotify()
{
    for (IObserver* observer : ObserverList)
    {
        observer->OnHealthChangeNotify(0);
    }
}

inline void IHealth::OnHealthChangeNotify()
{
    for (IObserver* observer : ObserverList)
    {
        observer->OnHealthChangeNotify(CurrentHealth);
    }
}
