//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Beacon of Hope");
    addSpecification("source", "background");
    addSpecification("description", "Your compassion shines like a light in darkness.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus charisma", 1);
    addSpecification("bonus persuasion", 1);

    addPrerequisite("/guilds/background/paths/compassionate/root.c",
        (["type":"research"]));
}
