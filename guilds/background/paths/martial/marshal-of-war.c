//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Marshal of War");
    addSpecification("source", "background");
    addSpecification("description",
        "You are a master of battlefield leadership and martial prowess.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus persuasion", 1);

    addPrerequisite("/guilds/background/paths/martial/strategic-mind.c",
        (["type":"research"]));
}
