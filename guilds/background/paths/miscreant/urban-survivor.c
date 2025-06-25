//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Urban Survivor");
    addSpecification("source", "background");
    addSpecification("description",
        "You know how to survive in the city, finding food, shelter, "
        "and opportunity where others see only danger.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus search", 1);
    addSpecification("bonus constitution", 1);

    addPrerequisite("/guilds/background/paths/miscreant/sly-tricks.c", 
        (["type":"research"]));
}
