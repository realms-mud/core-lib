//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Void Strike");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the knowledge to "
        "channel the emptiness of the void through a devastating strike.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/oblivion-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 53
        ]));

    addSpecification("limited by", (["equipment":
        ({ "long sword", "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 180);
    addSpecification("stamina point cost", 45);
    addSpecification("cooldown", 40);
    addSpecification("duration", 8);
    addSpecification("bonus magical attack", 45);
    addSpecification("bonus chaos attack", 15);

    addSpecification("modifiers", ({
        (["type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.10]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.05]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
    }));

    addSpecification("command template", "void strike");
    addSpecification("use ability message",
        "The void itself channels through ##InitiatorPossessive## blade.");
}
