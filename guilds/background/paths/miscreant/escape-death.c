//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Escape Death");
    addSpecification("source", "background");
    addSpecification("description",
        "You have an uncanny ability to survive situations that would "
        "kill most.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 5);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus heal hit points rate", 1);

    addPrerequisite("/guilds/background/paths/miscreant/second-wind.c", 
        (["type":"research"]));
}
