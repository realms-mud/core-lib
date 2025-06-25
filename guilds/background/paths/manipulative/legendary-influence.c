//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Influence");
    addSpecification("source", "background");
    addSpecification("description",
        "Your reputation for manipulation and persuasion is legendary.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus bluff", 1);
    addSpecification("bonus charisma", 1);

    addPrerequisite("/guilds/background/paths/manipulative/hidden-in-plain-sight.c",
        (["type":"research"]));
}
