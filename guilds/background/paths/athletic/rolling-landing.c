//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rolling Landing");
    addSpecification("source", "background");
    addSpecification("description",
        "You can absorb the impact of falls and landings, reducing harm.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus acrobatics", 1);
    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus defense class", 1);

    addPrerequisite("/guilds/background/paths/athletic/verticality.c",
        (["type":"research"]));
}
