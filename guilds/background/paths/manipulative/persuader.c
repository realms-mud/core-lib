//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Persuader");
    addSpecification("source", "background");
    addSpecification("description",
        "You are adept at convincing others to see things your way.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus barter", 1);
    addSpecification("bonus charisma", 1);

    addPrerequisite("/guilds/background/paths/manipulative/silver-tongue.c",
        (["type":"research"]));
}
