//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unflinching Focus");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "maintain perfect concentration under any conditions.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/arcane-precision.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus spell points", 35);
    addSpecification("bonus stamina points", 25);
}
