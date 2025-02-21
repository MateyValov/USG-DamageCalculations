#include <format> 
#include <iostream> 

#include "Target.h"

Target::Target(string InName)
{
    Name = InName;
}

Target::Target(string InName, float InSlashRes, float InPierceRes, float InBludgRes)
{
    Name = InName;
    SlashRes = InSlashRes;
    PierceRes = InPierceRes;
    BludgRes = InBludgRes;
}

void Target::DisplayStats()
{
    cout << "=======" << Name << "=======" << endl;
    cout << "SlashRes - " << SlashRes << "\nPierceRes - " << PierceRes << "\nBludgRes - " << BludgRes << endl;
    
    cout << "=======";
    for(int i = 0; i < Name.length(); i++)
    {
        cout << "=";
    }
    cout << "=======" << endl;
}