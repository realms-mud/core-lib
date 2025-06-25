//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unstoppable Force");
    addSpecification("source", "background");
    addSpecification("description",
        "You can break through obstacles and opponents with overwhelming "
        "power and momentum.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus strength", 1);
    addSpecification("bonus damage", 1);

    addPrerequisite("/guilds/background/paths/athletic/powerful-leap.c",
        (["type":"research"]));
}
