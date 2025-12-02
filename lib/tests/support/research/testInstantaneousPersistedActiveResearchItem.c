//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnTarget(string command, object owner, string researchName)
{
    return executeOnTarget(command, owner, researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteOnSelf(string command, object owner, string researchName)
{
    return executeOnSelf(command, owner, researchName);
}

/////////////////////////////////////////////////////////////////////////////
public int testExecuteInArea(string command, object owner, string researchName)
{
    return executeInArea(command, owner, researchName);
}
