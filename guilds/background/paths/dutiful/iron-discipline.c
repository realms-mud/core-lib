//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Iron Discipline");
    addSpecification("source", "background");
    addSpecification("description",
        "You are nearly impossible to sway from your chosen course.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus to intoxicated", 5);
    addSpecification("bonus to drugged", 5);
    addSpecification("bonus resist paralysis", 2);
    addSpecification("bonus defense class", 1);

    addPrerequisite("/guilds/background/paths/dutiful/steadfast.c",
        (["type":"research"]));
}
