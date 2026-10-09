//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancestral Nova");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald releases all their "
        "ancestor spirits in an explosive nova, dealing tremendous "
        "spiritual damage to all nearby enemies.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 14]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestral-wrath.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestral-vengeance.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke ancestral nova");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::release## every ancestor spirit in an explosive nova that scorches the entire area.");

    addSpecification("spell point cost", 55);
    addSpecification("stamina point cost", 22);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 90,
            "range": 100
        ]),
        ([
            "probability": 35,
            "base damage": 160,
            "range": 160
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
            "rate": 0.13
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.13
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/ancestral-wrath.c",
            "name": "Ancestral Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ])
    }));
    addSpecification("consumables", (["elder ward rune": 1]));
}
