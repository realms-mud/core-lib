//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primal Rune Nova");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald shatters a primal rune "
        "in a catastrophic area nova, dealing devastating elemental damage "
        "to every enemy in the vicinity.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 28]));
    addPrerequisite("/guilds/runeskald/elder-runes/ancient-rune-nova.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/elder-runes/primal-rune-burst.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 30);
    addSpecification("command template", "primal rune nova");
    addSpecification("use ability message",
        "##InitiatorName## shatters a primal rune, unleashing a nova of primordial destruction across the entire area.");

    addSpecification("spell point cost", 80);
    addSpecification("stamina point cost", 35);

    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 250,
            "range": 250
        ]),
        ([
            "probability": 40,
            "base damage": 400,
            "range": 400
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
            "rate": 0.28
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/elder-runes/ancient-rune-nova.c",
            "name": "Ancient Rune Nova",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ])
    }));
    addSpecification("consumables", (["primal power rune": 1]));
}
