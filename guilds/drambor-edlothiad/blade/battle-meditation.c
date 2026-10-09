//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battle Meditation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "maintain a meditative state during combat, improving mana and "
        "stamina efficiency.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/elven-swordcraft.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spell points", 30);
    addSpecification("bonus stamina points", 20);
    addSpecification("bonus spellcraft", 3);
}
