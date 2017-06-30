//*****************************************************************************
// Class: races
// File Name: races.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/race.h"

/////////////////////////////////////////////////////////////////////////////
private nomask object racialDictionary()
{
    return getDictionary("racial");
}

/////////////////////////////////////////////////////////////////////////////
static nomask string *validRace()
{
    return racialDictionary()->validRaces();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidRace(string race)
{
    return racialDictionary()->isValidRace(race);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string Race(string newRace)
{
    if(newRace && !getService("player") || (getService("player") && isValidRace(newRace)))
    {
        race = newRace;
    }
    return race;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *racesExtraAttacks()
{
    return racialDictionary()->extraAttacks(Race());
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *racesResearchTrees()
{
    return racialDictionary()->researchTrees(Race());
}

/////////////////////////////////////////////////////////////////////////////
public nomask int racesAttributeBonus(string attribute)
{
    int ret = 0;
    
    if(attribute && stringp(attribute))
    {
        string method = sprintf("%sBonus", capitalize(attribute));
        if(function_exists(method, racialDictionary()))
        {
            ret = call_other(racialDictionary(), method, Race());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int racesBonusTo(string bonus)
{
    int ret = 0;
    
    if(function_exists(bonus, racialDictionary()))
    {
        ret = call_other(racialDictionary(), bonus, Race());
    }
    else if(function_exists("BonusSkillModifier", racialDictionary()))
    {
        ret = call_other(racialDictionary(), 
            "BonusSkillModifier", Race(), bonus);
    }
    return ret;
}

