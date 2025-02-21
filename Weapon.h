#pragma once

#include "string"

using namespace std;

enum EDamageType 
{
    None,
    Slashing,
    Piercing,
    Bludgeoning
};

enum EWeight 
{
    VeryLight = 1,
    Light = 5,
    Normal = 10,
    Heavy = 20,
    VeryHeavy = 30
};

class Weapon
{
public:

    Weapon(){};
    Weapon(string InName);
    Weapon(string InName, float InBaseDamage, float InPenetration, EDamageType InDamageType, EWeight InWeight);

    string Name;

    float BaseDamage = 0.f;
    float Penetration = 0.f;
    float PenetrationMultiplier = 1.f;
    
    EDamageType DamageType = EDamageType::None;
    EWeight Weight = EWeight::Normal;

    string GetDamageType();
    string GetWeight();

    void DisplayStats();

};