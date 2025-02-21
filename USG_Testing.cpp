#include "iostream"

#include "Attacker.h"
#include "Weapon.h"

using namespace std;

int main()
{
    Attacker Attacker1 = Attacker("Barbarian");
    Attacker1.Strength = 10;
    Attacker1.Dexterity = 10;
    Attacker1.SlashRes = 10;
    Attacker1.PierceRes = 10;
    Attacker1.BludgRes = 10;

    Target Target1 = Target("Rock");
    Target1.SlashRes = 10;
    Target1.PierceRes = 10;
    Target1.BludgRes = 10;
    
    Weapon Weapon1 = Weapon("Sword");
    Weapon1.BaseDamage = 10;
    Weapon1.Penetration = 10;
    Weapon1.DamageType = EDamageType::Slashing;
    Weapon1.Weight = EWeight::Normal;
    
    Attacker1.SetWeapon(&Weapon1);
    
    Attacker1.DisplayStats();
    Weapon1.DisplayStats();
    Target1.DisplayStats();

    Attacker1.CalculateAttackSpeed(0);
    Attacker1.CalculateAttackSpeed(5);
    Attacker1.CalculateAttackSpeed(10);

    Attacker1.DealDamage(&Target1, 0);
    Attacker1.DealDamage(&Target1, 5);
    Attacker1.DealDamage(&Target1, 10);

    return 0;
}

