//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master Negotiator");
    addSpecification("source", "background");
    addSpecification("description",
        "You excel at brokering deals and finding common ground.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus barter", 1);
    addSpecification("bonus intelligence", 1);

    addPrerequisite("/guilds/background/paths/manipulative/persuader.c",
        (["type":"research"]));
}
