//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Detonation");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald detonates all active "
        "inscribed runes simultaneously, releasing their stored energy "
        "as a powerful multi-element explosion striking all nearby foes.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 16]));
    addPrerequisite("/guilds/runeskald/elder-runes/rune-barrage.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 40);
    addSpecification("command template", "rune detonation");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::trigger## a catastrophic chain detonation as all their inscribed runes explode at once.");

    addSpecification("spell point cost", 55);
    addSpecification("stamina point cost", 25);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 100,
            "range": 100
        ]),
        ([
            "probability": 35,
            "base damage": 180,
            "range": 180
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
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/elder-rune-blast.c",
            "name": "Elder Rune Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ])
    }));
    addSpecification("consumables", (["ancient power rune": 1]));
}
