//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hidden Motives");
    addSpecification("source", "background");
    addSpecification("description",
        "You are skilled at detecting deception and reading intentions.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus bluff", 1);
    addSpecification("bonus wisdom", 1);

    addPrerequisite("/guilds/background/paths/manipulative/keen-observer.c",
        (["type":"research"]));
}
