//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public object testGetTarget(object owner, string command)
{
    return persistedActiveResearchItem::getTarget(owner, command);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return persistedActiveResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnSelf(string unparsedCommand, object owner, 
    string researchName)
{
    return persistedActiveResearchItem::executeOnSelf(unparsedCommand, owner, 
        researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnTarget(string unparsedCommand, object owner,
    string researchName)
{
    return persistedActiveResearchItem::executeOnTarget(unparsedCommand, owner,
        researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteInArea(string unparsedCommand, object owner, 
    string researchName)
{
    return persistedActiveResearchItem::executeInArea(unparsedCommand, owner,
        researchName);
}
