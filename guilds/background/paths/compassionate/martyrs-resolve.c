//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Martyr's Resolve");
    addSpecification("source", "background");
    addSpecification("description", "You are willing to endure any hardship "
        "to protect and heal others.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus stamina points", 5);
    addSpecification("bonus hit points", 5);

    addPrerequisite("/guilds/background/paths/compassionate/root.c",
        (["type":"research"]));
}
