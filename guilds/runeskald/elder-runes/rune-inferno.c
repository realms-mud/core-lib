//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Inferno");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald hurls a blazing fire rune "
        "that erupts on impact, engulfing a target in a column of rune-fire.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 15]));
    addPrerequisite("/guilds/runeskald/elder-runes/twin-rune-strike.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "rune inferno ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hurl## a fire rune that erupts in a column of runic flame around ##TargetName##.");

    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 80,
            "range": 90
        ]),
        ([
            "probability": 30,
            "base damage": 140,
            "range": 140
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/runic-precision.c",
            "name": "runic-precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/runic-efficiency.c",
            "name": "runic-efficiency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/runic-alacrity.c",
            "name": "runic-alacrity",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/runic-precision-ii.c",
            "name": "runic-precision-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/runic-efficiency-ii.c",
            "name": "runic-efficiency-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/runic-alacrity-ii.c",
            "name": "runic-alacrity-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/runic-precision-iii.c",
            "name": "runic-precision-iii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/elder-rune-blast.c",
            "name": "Elder Rune Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.18
        ])
    }));
    addSpecification("consumables", (["ancient power rune": 1]));
}
