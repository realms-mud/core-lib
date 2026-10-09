//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Twin Rune Strike");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald detonates two runes "
        "simultaneously at a single target, dealing a powerful double "
        "burst of elemental damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 11]));
    addPrerequisite("/guilds/runeskald/elder-runes/rune-volley.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "twin rune strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::detonate## twin runes in rapid succession against ##TargetName##.");

    addSpecification("spell point cost", 38);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 70,
            "range": 70
        ]),
        ([
            "probability": 30,
            "base damage": 120,
            "range": 120
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
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.17
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/elder-rune-blast.c",
            "name": "Elder Rune Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));
    addSpecification("consumables", (["elder power rune": 1]));
}
