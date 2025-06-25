//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Political Savvy");
    addSpecification("source", "background");
    addSpecification("description",
        "You are adept at navigating complex social and political situations.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus etiquette", 1);
    addSpecification("bonus intelligence", 1);

    addPrerequisite("/guilds/background/paths/manipulative/master-negotiator.c",
        (["type":"research"]));
}
