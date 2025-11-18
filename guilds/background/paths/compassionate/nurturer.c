//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nurturer");
    addSpecification("source", "background");
    addSpecification("description", "You have spent countless hours caring "
        "for the vulnerable.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus cooking", 1);
    addSpecification("bonus herbalism", 1);

    addPrerequisite("/guilds/background/paths/compassionate/protective-nature.c",
        (["type":"research"]));
}
