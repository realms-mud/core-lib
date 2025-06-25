//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Powerful Leap");
    addSpecification("source", "background");
    addSpecification("description",
        "You can leap great distances and heights, clearing obstacles with "
        "ease.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus acrobatics", 1);
    addSpecification("bonus strength", 1);
    addSpecification("bonus stamina points", 2);

    addPrerequisite("/guilds/background/paths/athletic/long-distance.c",
        (["type":"research"]));
}
