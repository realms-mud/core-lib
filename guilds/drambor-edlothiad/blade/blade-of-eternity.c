//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blade of Eternity");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the ultimate "
        "technique  of the Drambor Edlothiad: the Blade of Eternity, where "
            "the battlemage "
        "channels the accumulated wisdom of millennia into devastating "
            "strikes.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/arcane-annihilation.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 63
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 175);
    addSpecification("stamina point cost", 90);
    addSpecification("cooldown", 240);
    addSpecification("duration", 150);
    addSpecification("bonus attack", 18);
    addSpecification("bonus magical attack", 20);
    addSpecification("bonus damage", 12);

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
        (["type": "research",
            "research item": 
                "/guilds/drambor-edlothiad/blade/bladestorm-mastery.c",
            "name": "bladestorm-mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25]),
        (["type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.20]),
        (["type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.75]),
        (["type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.20]),
        (["type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.10]),
    }));

    addSpecification("command template", "blade of eternity");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "blade blazes with the accumulated power of eternity, each strike "
        "resonating with millennia of elven warfare.");
}
