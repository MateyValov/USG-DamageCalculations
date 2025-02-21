#pragma once

#include "Target.h"
#include "Weapon.h"

class Attacker : public Target
{
public:

    Attacker(){};
    Attacker(string InName);
    Attacker(string InName, float InStrength, float InDexterity, float InSlashres, float InPierceRes, float InBludgRes);

    float Strength = 0.f;
    float Dexterity = 0.f;

    Weapon* AttackerWeapon = nullptr;

    void DisplayStats() override;

    void SetWeapon(Weapon* InWeapon);
    
    void CalculateAttackSpeed(float MovementSpeed);

    void DealDamage(Target* Target, float MovementSpeed);

};