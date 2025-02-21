#include <iostream> 
#include <cmath>

#include "Attacker.h"

using namespace std;

Attacker::Attacker(string InName)
{
    Name = InName;
}

Attacker::Attacker(string InName, float InStrength, float InDexterity, float InSlashres, float InPierceRes, float InBludgRes)
{
    Name = InName;
    Strength = InStrength;
    Dexterity = InDexterity;
    SlashRes = InSlashres;
    PierceRes = InPierceRes;
    BludgRes = InBludgRes;
}

void Attacker::DisplayStats()
{
    cout << "=======" << Name << "=======" << endl;
    cout << "Strength - " << Strength << "\nDexterity - " << Dexterity << "\nSlashRes - " << SlashRes 
    << "\nPierceRes - " << PierceRes << "\nBludgRes - " << BludgRes << endl;
    
    cout << "=======";
    for(int i = 0; i < Name.length(); i++)
    {
        cout << "=";
    }
    cout << "=======" << endl;
}

void Attacker::SetWeapon(Weapon* InWeapon)
{
    AttackerWeapon = InWeapon;
}
    
void Attacker::CalculateAttackSpeed(float MovementSpeed)
{
    if(AttackerWeapon == nullptr)
    {
        cout << Name <<" doesn't have a weapon!" << endl;
        return;
    }

    float StrengthMultiplier = Strength/AttackerWeapon->Weight;
    float DexterityMultiplier = Dexterity/2;

    float AttackSpeed = 1 + 1 * StrengthMultiplier * MovementSpeed/100 * DexterityMultiplier;
    
    cout << Name << " has " << AttackSpeed << " attack speed at " << MovementSpeed << "m/s" << endl;
}

void Attacker::DealDamage(Target* Target, float MovementSpeed)
{
    if(AttackerWeapon == nullptr)
    {
        cout << Name <<" doesn't have a weapon!" << endl;
        return;
    }

    float StrengthMultiplier = Strength/AttackerWeapon->Weight;
    
    float TargetResistance;
    switch(AttackerWeapon->DamageType)
    {
        case Slashing: TargetResistance = Target->SlashRes; break;
        case Piercing: TargetResistance = Target->PierceRes; break;
        case Bludgeoning: TargetResistance = Target->BludgRes;
    }

    float PenetrationMultiplier = (AttackerWeapon->Penetration + AttackerWeapon->Penetration * AttackerWeapon->PenetrationMultiplier + AttackerWeapon->Penetration * MovementSpeed / 100) / TargetResistance;
    float FinalDamage = AttackerWeapon->BaseDamage * StrengthMultiplier * PenetrationMultiplier;

    cout << Name << " deals " << floor(FinalDamage) << " damage with " << MovementSpeed << "m/s velocity" << endl;
}