//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Strike");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "channel raw mana into their blade strikes, adding arcane force "
        "to each blow for a brief duration.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spellblade-form.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 60);
    addSpecification("duration", 60);
    addSpecification("bonus attack", 3);
    addSpecification("bonus magical attack", 3);

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
        (["type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.03]),
    }));

    addSpecification("command template", "mana strike");
    addSpecification("use ability message", "Arcane energy surges through "
        "##InitiatorPossessive## blade as mana infuses each strike.");
}
