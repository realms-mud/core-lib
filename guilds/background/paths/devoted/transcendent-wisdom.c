//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendent Wisdom");
    addSpecification("source", "background");
    addSpecification("description", "Your understanding has reached heights "
        "few ever achieve.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus spell points", 10);

    addPrerequisite("/guilds/background/paths/devoted/enlightened-mind.c",
        (["type":"research"]));
}
