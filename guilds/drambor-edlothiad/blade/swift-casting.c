//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Swift Casting");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches rapid spell "
        "integration  with blade techniques for faster combat casting.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/mana-flow.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 4);
    addSpecification("bonus attack", 3);
}
