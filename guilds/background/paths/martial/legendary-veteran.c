//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Veteran");
    addSpecification("source", "background");
    addSpecification("description",
        "Your experience and skill are the stuff of legend, inspiring all "
        "who fight beside you.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus hit points", 5);

    addPrerequisite("/guilds/background/paths/martial/relentless-advance.c",
        (["type":"research"]));
}
