//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Understanding Heart");
    addSpecification("source", "background");
    addSpecification("description", "Your deep empathy allows you to sense "
        "the emotional wounds others carry.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus diplomacy", 1);

    addPrerequisite("/guilds/background/paths/compassionate/empathic-sense.c",
        (["type":"research"]));
}
