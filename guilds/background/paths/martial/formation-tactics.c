//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Formation Tactics");
    addSpecification("source", "background");
    addSpecification("description",
        "You understand the importance of teamwork and battlefield "
        "positioning.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus parry", 1);
    addSpecification("bonus defense class", 1);

    addPrerequisite("/guilds/background/paths/martial/weapon-familiarity.c",
        (["type":"research"]));
}
