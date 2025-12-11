//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Constructed Test Root");
    addSpecification("source", "blarg");
    addSpecification("description", "Test constructed research root");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 10);
    addSpecification("command name", "test spell");
    addSpecification("command template", "test spell ##Value##");
    addSpecification("cooldown", 10);
    addSpecification("maximum constructed size", 5);
}
