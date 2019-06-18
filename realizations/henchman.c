//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/guilds.c";
virtual inherit "/lib/modules/quests.c";
virtual inherit "/lib/modules/conversations.c";
virtual inherit "/lib/modules/crafting.c";
virtual inherit "/lib/modules/personas.c";
virtual inherit "/lib/modules/combatChatter.c";

private object Leader;
private string Location;
private mapping Activity = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfHenchman()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxHitPoints(int value)
{
    maxHitPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "hitPoints",
        call_direct(this_object(), "maxHitPoints"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxSpellPoints(int value)
{
    maxSpellPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "spellPoints",
        call_direct(this_object(), "maxSpellPoints"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxStaminaPoints(int value)
{
    maxStaminaPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "staminaPoints",
        call_direct(this_object(), "maxStaminaPoints"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setLeader(object player)
{
    Leader = player;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    if (Leader && Leader->getDomainType(location))
    {
        Location = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string location()
{
    return Location;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setActivity(mapping activity)
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (Leader && Leader->getDomainType(Location) &&
        dictionary->isValidActivity(Location, activity))
    {
        Activity = activity + ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping activity()
{
    return Activity + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string partyName()
{
    string ret = 0;
    if (Leader)
    {
        ret = Leader->RealName();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty()
{
    object ret = this_object();
    if (Leader && Leader->getParty())
    {
        ret = Leader->getParty();
    }
    return ret;
}
