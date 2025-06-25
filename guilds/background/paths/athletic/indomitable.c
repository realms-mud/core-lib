//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Indomitable");
    addSpecification("source", "background");
    addSpecification("description",
        "Your will and body are unbreakable, allowing you to resist even the "
        "most dire threats.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist paralysis", 5);
    addSpecification("bonus resist poison", 5);
    addSpecification("bonus defense class", 1);

    addPrerequisite("/guilds/background/paths/athletic/peak-performance.c",
        (["type":"research"]));
}
