//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Arcane War");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ultimate synthesis of arcane "
        "and martial mastery. The battlemage becomes "
        "a living embodiment of the Drambor ideal: "
        "a warrior whose every movement channels "
        "devastating sorcery and whose every spell "
        "is honed to a razor's lethal edge.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "arcane-supremacy.c",
        (["type": "research"]));
    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "timeless-combatant.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 6);
    addSpecification("bonus defense", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus spell points", 50);
    addSpecification("bonus stamina points", 50);
}
