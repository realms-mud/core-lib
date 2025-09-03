//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/races.h"

/////////////////////////////////////////////////////////////////////////////
private nomask object RaceService()
{
    return getService("racial");
}

/////////////////////////////////////////////////////////////////////////////
static nomask string *validRace()
{
    return RaceService()->validRaces();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidRace(string race)
{
    return RaceService()->isValidRace(race);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string apparentRace(string newRace)
{
    if (newRace && !getModule("player"))
    {
        apparentRace = newRace;
    }
    return apparentRace ? apparentRace : race;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string Race(string newRace)
{
    if (newRace)
    {
        newRace = lower_case(newRace);

        if (!getModule("player") || (getModule("player") &&
            isValidRace(newRace) && !RaceService()->isCreatureRace(newRace)))
        {
            race = newRace;
        }
    }
    return race;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string racialType()
{
    return RaceService()->racialType(this_object());
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *racesExtraAttacks()
{
    return RaceService()->extraAttacks(Race());
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *racesResearchTrees()
{
    return RaceService()->researchTrees(Race());
}

/////////////////////////////////////////////////////////////////////////////
public nomask int racesAttributeBonus(string attribute)
{
    int ret = 0;
    
    if(attribute && stringp(attribute))
    {
        string method = sprintf("%sBonus", capitalize(attribute));
        if(function_exists(method, RaceService()))
        {
            ret = call_other(RaceService(), method, Race());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int racesBonusTo(string bonus)
{
    int ret = 0;
    
    if(function_exists(bonus, RaceService()))
    {
        ret = call_other(RaceService(), bonus, Race());
    }
    else if(function_exists("BonusSkillModifier", RaceService()))
    {
        ret = call_other(RaceService(), 
            "BonusSkillModifier", Race(), bonus);
    }
    return ret;
}
