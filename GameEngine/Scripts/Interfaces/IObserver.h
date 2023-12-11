#pragma once

class IObserver
{
public:
    IObserver() = default;
    virtual ~IObserver() {}
    virtual void OnNotify();
    virtual void OnNotify(int i);
    virtual IObserver* GetObserver() { return this; }
};