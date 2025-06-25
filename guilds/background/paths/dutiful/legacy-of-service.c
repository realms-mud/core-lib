//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legacy of Service");
    addSpecification("source", "background");
    addSpecification("description",
        "Your reputation for duty and service inspires those around you.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus hit points", 5);

    addPrerequisite("/guilds/background/paths/dutiful/efficient-worker.c",
        (["type":"research"]));
}
