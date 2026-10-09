//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Axe Cleave");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald swings a rune-bound axe "
        "in a broad horizontal arc, striking two nearby foes with runic force.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 5]));
    addPrerequisite("/guilds/runeskald/rune-warrior/rune-bound-axe.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "rune axe cleave");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::swing## their rune-bound axe in a brutal arc, biting into nearby foes.");

    addSpecification("spell point cost", 20);
    addSpecification("stamina point cost", 18);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 22,
            "range": 22
        ]),
        ([
            "probability": 20,
            "base damage": 45,
            "range": 35
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-might.c",
            "name": "warriors-might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-endurance.c",
            "name": "warriors-endurance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-tempo.c",
            "name": "warriors-tempo",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-might-ii.c",
            "name": "warriors-might-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-endurance-ii.c",
            "name": "warriors-endurance-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "axe",
            "formula": "additive",
            "rate": 0.07
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/paint-rune-of-strength.c",
            "name": "Paint Rune of Strength",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ])
    }));
    addSpecification("consumables", (["basic blade rune": 1]));
}
