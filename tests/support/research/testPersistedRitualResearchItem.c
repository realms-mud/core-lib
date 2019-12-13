//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedRitualResearchItem.c";

private int useRitual;

public void TogglePerformRitual()
{
    useRitual = !useRitual;
}

/////////////////////////////////////////////////////////////////////////////
public int ritualMultiplier(string type, int value)
{
    return value * (useRitual +1);
}

/////////////////////////////////////////////////////////////////////////////
public object testGetTarget(object owner, string command)
{
    return baseCommand::getTarget(owner, command);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return persistedRitualResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnSelf(object owner, string researchName)
{
    return persistedRitualResearchItem::executeOnSelf(owner, researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    return persistedRitualResearchItem::executeOnTarget(unparsedCommand, owner,
        researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteInArea(object owner, string researchName)
{
    return persistedRitualResearchItem::executeInArea(owner, researchName);
}
