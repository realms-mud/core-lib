//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "False Face");
    addSpecification("source", "background");
    addSpecification("description",
        "You are skilled at hiding your true feelings and intentions.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus disguise", 1);
    addSpecification("bonus bluff", 1);
    addSpecification("bonus charisma", 1);

    addPrerequisite("/guilds/background/paths/manipulative/quick-lie.c",
        (["type":"research"]));
}
