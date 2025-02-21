#pragma once

#include "string"

using namespace std;

class Target
{
public:

    Target(){};
    Target(string InName);
    Target(string InName, float InSlashRes, float InPierceRes, float InBludgRes);

    string Name;

    float SlashRes = 0.f;
    float PierceRes = 0.f;
    float BludgRes = 0.f;

    virtual void DisplayStats();

};