//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chain Rune");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald hurls a rune-stone that "
        "rebounds between nearby enemies, striking up to three foes in "
        "sequence with diminishing elemental force.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 6]));
    addPrerequisite("/guilds/runeskald/elder-runes/sundering-rune.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "chain rune ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::launch## a rune-stone that bounces between nearby foes, striking ##TargetName## first.");

    addSpecification("spell point cost", 28);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 24,
            "range": 26
        ]),
        ([
            "probability": 25,
            "base damage": 48,
            "range": 45
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
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/rune-burst.c",
            "name": "Rune Burst",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ])
    }));
    addSpecification("consumables", (["basic power rune": 1]));
}
