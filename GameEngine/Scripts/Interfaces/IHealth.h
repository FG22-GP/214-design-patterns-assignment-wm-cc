#pragma once
#include <list>

#include "IObserver.h"


class IHealth
{
public:
    virtual ~IHealth() = default;
    // virtual void TakeDamage(int DamageTaken);
    void GainHealth(int HealthGained);
    int GetCurrentHealth();
    bool GetIsDead();
    void AddObserver(IObserver* observer);
    void RemoveObserver(IObserver* observer);
    void OnDeathNotify();
    void OnHitNotify();

protected:
    int MaxHealth = 10;
    int CurrentHealth = 10;
    bool bIsDead = false;
    std::list<IObserver*> ObserverList;
};

// inline void IHealth::TakeDamage(int damageTaken)
// {
//     if (bIsDead) return;
//     
//     CurrentHealth -= damageTaken;
//     OnHitNotify();
//     if (CurrentHealth <= 0)
//     {
//         OnDeathNotify();
//         bIsDead = true;
//     }
// }

inline void IHealth::GainHealth(int HealthGained)
{
    if (bIsDead || CurrentHealth >= MaxHealth) return;

    CurrentHealth += HealthGained;
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
        observer->OnNotify();
    }
}

inline void IHealth::OnHitNotify()
{
    for (IObserver* observer : ObserverList)
    {
        observer->OnNotify(CurrentHealth);
    }
}
