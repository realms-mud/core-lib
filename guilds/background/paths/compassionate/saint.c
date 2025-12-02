//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Saint");
    addSpecification("source", "background");
    addSpecification("description", "Your unwavering compassion has elevated "
        "you to near-legendary status.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus charisma", 2);
    addSpecification("bonus wisdom", 1);

    addPrerequisite("/guilds/background/paths/compassionate/selfless-devotion.c",
        (["type":"research"]));
}
