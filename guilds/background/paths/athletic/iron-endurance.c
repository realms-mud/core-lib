//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Iron Endurance");
    addSpecification("source", "background");
    addSpecification("description",
        "You can withstand fatigue, pain, and hardship far beyond the norm.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 5);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus resist disease", 2);

    addPrerequisite("/guilds/background/paths/athletic/relentless.c",
        (["type":"research"]));
}
