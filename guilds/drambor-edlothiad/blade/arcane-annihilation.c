//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Annihilation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the devastating "
        "arcane  annihilation technique, where each blade strike is a "
            "focused "
        "detonation of accumulated magical energy.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spellstorm-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("stamina point cost", 60);
    addSpecification("cooldown", 180);
    addSpecification("duration", 120);
    addSpecification("bonus attack", 12);
    addSpecification("bonus magical attack", 15);
    addSpecification("bonus damage", 8);

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
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/blade/spell-weave-transcendence.c",
            "name": "spell-weave-transcendence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.15]),
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
            "rate": 0.10]),
    }));

    addSpecification("command template", "arcane annihilation");
    addSpecification("use ability message", "Each strike of ##InitiatorPossessive## "
        "blade detonates with accumulated arcane energy, sending waves of "
        "annihilating force into ##InitiatorPossessive## target.");
}
