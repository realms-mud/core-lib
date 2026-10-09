//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Bolt");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald fires a bolt of concentrated "
        "rune energy at a single target, dealing solid elemental damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 4]));
    addPrerequisite("/guilds/runeskald/elder-runes/rune-pulse.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "rune bolt ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::fire## a crackling bolt of rune energy at ##TargetName##.");

    addSpecification("spell point cost", 18);
    addSpecification("stamina point cost", 8);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 22,
            "range": 28
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 50
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
            "rate": 1.10
        ])
    }));
    addSpecification("consumables", (["basic power rune": 1]));
}
