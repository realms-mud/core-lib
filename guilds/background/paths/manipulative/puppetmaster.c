//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Puppetmaster");
    addSpecification("source", "background");
    addSpecification("description",
        "You excel at manipulating others to do your bidding.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus bluff", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus charisma", 1);

    addPrerequisite("/guilds/background/paths/manipulative/insightful.c",
        (["type":"research"]));
}
