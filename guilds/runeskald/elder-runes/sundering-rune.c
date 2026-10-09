//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sundering Rune");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald hurls a rune-stone that "
        "shatters against a foe's armor with a tearing burst, dealing "
        "physical and rune-force damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 5]));
    addPrerequisite("/guilds/runeskald/elder-runes/rune-bolt.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "sundering rune ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hurl## a sundering rune-stone that tears into ##TargetName##.");

    addSpecification("spell point cost", 22);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 28,
            "range": 32
        ]),
        ([
            "probability": 25,
            "base damage": 55,
            "range": 55
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
            "rate": 0.11
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
