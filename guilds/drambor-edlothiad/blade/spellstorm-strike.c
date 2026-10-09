//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spellstorm Strike");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to "
        "unleash a storm of arcane strikes, each blow sending shockwaves "
        "of magical energy outward.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/runic-blade.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 23
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 150);
    addSpecification("duration", 105);
    addSpecification("bonus attack", 8);
    addSpecification("bonus magical attack", 10);
    addSpecification("bonus damage", 5);

    addSpecification("modifiers", ({
        (["type": "research",
            "research item": "/guilds/drambor-edlothiad/blade/spell-weave.c",
            "name": "spell-weave",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/blade/spell-weave-mastery.c",
            "name": "spell-weave-mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.10]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.50]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.15]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05]),
    }));

    addSpecification("command template", "spellstorm strike");
    addSpecification("use ability message", "A storm of arcane energy erupts "
        "from ##InitiatorPossessive## blade with each strike, sending "
            "shockwaves "
        "of magical force outward.");
}
