//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Memory of Ages");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research unlocks memories "
        "stretching back through generations.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/timeless-wisdom.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus spellcraft", 3);
}
