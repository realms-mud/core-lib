//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unyielding");
    addSpecification("source", "background");
    addSpecification("description",
        "You refuse to back down, even in the face of overwhelming odds.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 3);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus constitution", 1);

    addPrerequisite("/guilds/background/paths/martial/quick-reaction.c",
        (["type":"research"]));
}
