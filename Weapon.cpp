#include "iostream"

#include "Weapon.h"

using namespace std;

Weapon::Weapon(string InName)
{
    Name = InName;
}

Weapon::Weapon(string InName, float InBaseDamage, float InPenetration, EDamageType InDamageType, EWeight InWeight)
{
    Name = InName;
    BaseDamage = InBaseDamage;
    Penetration = InPenetration;
    DamageType = InDamageType;
    Weight = InWeight;
}

string Weapon::GetDamageType()
{
    switch(DamageType)
    {
        case EDamageType::None: return "None";
        case EDamageType::Slashing: return "Slashing";
        case EDamageType::Piercing: return "Piercing";
        case EDamageType::Bludgeoning: return "Bludgeoning";
        default: return "Error";
    }
}

string Weapon::GetWeight()
{
    switch(Weight)
    {
        case EWeight::VeryLight: return "VeryLight";
        case EWeight::Light: return "Light";
        case EWeight::Normal: return "Normal";
        case EWeight::Heavy: return "Heavy";
        case EWeight::VeryHeavy: return "VeryHeavy";
        default: return "Error";
    }
}

void Weapon::DisplayStats()
{
    cout << "=======" << Name << "=======" << endl;
    cout << "BaseDamage - " << BaseDamage << "\nPenetration - " << Penetration << "\nDamageType - " << this->GetDamageType() 
    << "\nWeight - " << this->GetWeight() << endl;
    
    cout << "=======";
    for(int i = 0; i < Name.length(); i++)
    {
        cout << "=";
    }
    cout << "=======" << endl;
}