//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Burst");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald shatters a basic storm, "
        "frost, or flame rune in hand, releasing its energy as a blast "
        "of elemental force against a single enemy. More powerful than "
        "standard spells due to the cost of the consumed rune.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 3]));
    addPrerequisite("/guilds/runeskald/elder-runes/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "rune burst ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## shatters a rune-stone, blasting ##TargetName## with raw elemental force.");

    addSpecification("spell point cost", 10);
    addSpecification("stamina point cost", 5);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 25,
            "range": 30
        ]),
        ([
            "probability": 25,
            "base damage": 45,
            "range": 60
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
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ])
    }));
    addSpecification("consumables", (["basic power rune": 1]));
}
