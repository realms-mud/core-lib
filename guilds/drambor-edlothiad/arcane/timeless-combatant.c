//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Timeless Combatant");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the timeless combat awareness of "
        "the eldest elven warriors. Having internalized "
        "lifetimes of battle experience, the "
        "battlemage fights with the unhurried "
        "certainty of one who has seen every possible "
        "attack and knows its counter intimately.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "eternal-warrior.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 53
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus parry", 4);
    addSpecification("bonus wisdom", 1);
}
