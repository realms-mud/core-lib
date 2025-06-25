//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Organized Mind");
    addSpecification("source", "background");
    addSpecification("description",
        "You keep your thoughts and tasks well-ordered and efficient.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist paralysis", 5);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus resist psionic", 5);

    addPrerequisite("/guilds/background/paths/dutiful/cleanly-habits.c",
        (["type":"research"]));
}
