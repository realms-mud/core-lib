//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Strategic Mind");
    addSpecification("source", "background");
    addSpecification("description",
        "You excel at planning, anticipating, and outmaneuvering your foes.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus defense", 1);

    addPrerequisite("/guilds/background/paths/martial/weapon-mastery.c",
        (["type":"research"]));
}
