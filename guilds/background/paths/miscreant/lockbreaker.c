//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lockbreaker");
    addSpecification("source", "background");
    addSpecification("description",
        "You are adept at bypassing locks and security measures.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus open lock", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus disable traps", 1);

    addPrerequisite("/guilds/background/paths/miscreant/poison-affinity.c", 
        (["type":"research"]));
}
