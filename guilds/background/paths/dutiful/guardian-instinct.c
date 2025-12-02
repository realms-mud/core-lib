//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Guardian Instinct");
    addSpecification("source", "background");
    addSpecification("description",
        "You are quick to protect those in your care.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus parry", 1);
    addSpecification("bonus hit points", 3);

    addPrerequisite("/guilds/background/paths/dutiful/keen-memory.c",
        (["type":"research"]));
}
