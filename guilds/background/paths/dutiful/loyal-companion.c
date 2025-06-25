//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Loyal Companion");
    addSpecification("source", "background");
    addSpecification("description",
        "You are steadfast and loyal, always supporting your allies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus animal handling", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus resist psionic", 5);

    addPrerequisite("/guilds/background/paths/dutiful/obedient-mind.c",
        (["type":"research"]));
}
