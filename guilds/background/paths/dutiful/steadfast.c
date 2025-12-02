//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Steadfast");
    addSpecification("source", "background");
    addSpecification("description",
        "You are unwavering in your duties and commitments.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist paralysis", 2);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus hit points", 3);

    addPrerequisite("/guilds/background/paths/dutiful/loyal-companion.c",
        (["type":"research"]));
}
