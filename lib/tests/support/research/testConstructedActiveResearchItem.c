//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return constructedActiveResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public mapping testGetUsageCosts(string command, object initiator)
{
    return getUsageCosts(command, initiator);
}

/////////////////////////////////////////////////////////////////////////////
public int testCooldown(object initiator, string command)
{
    return cooldown(initiator, command);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Constructed Research");
    addSpecification("source", "test");
    addSpecification("description", "This is a test constructed active research item.");
    addSpecification("scope", "area");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);
    addSpecification("command template", "test spell ##Target##");
    addSpecification("command name", "test spell");
    addSpecification("cooldown", 10);
    addSpecification("maximum constructed size", 3);
}

/////////////////////////////////////////////////////////////////////////////
public int testGetRepeatEffectCount(string command, object initiator)
{
    return getRepeatEffectCount(command, initiator);
}
