#pragma once

class IObserver
{
public:
    IObserver() = default;
    virtual ~IObserver() = default;
    virtual void OnHealthChangeNotify(int i);
    
};

inline void IObserver::OnHealthChangeNotify(int i)
{
}
