//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrathful Barrage");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels the collective "
        "wrath of their bloodline into a surging barrage of spiritual "
        "missiles that strikes all nearby enemies.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 9]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-barrage.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestral-wrath.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke wrathful barrage");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## a surge of ancestral wrath into a barrage of spiritual missiles.");

    addSpecification("spell point cost", 38);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 42,
            "range": 48
        ]),
        ([
            "probability": 30,
            "base damage": 80,
            "range": 75
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/spirits-wrath.c",
            "name": "spirits-wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/spirits-reserve.c",
            "name": "spirits-reserve",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/spirits-haste.c",
            "name": "spirits-haste",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/ancestral-wrath.c",
            "name": "Ancestral Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));
    addSpecification("consumables", (["elder ward rune": 1]));
}
