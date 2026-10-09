//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Shatter");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald compresses ancestral "
        "energy to a fine point and then detonates it inside a target, "
        "dealing heavy spiritual damage in a single explosive burst.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 10]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-storm.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke spirit shatter ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::compress## a sphere of ancestral energy inside ##TargetName## and detonate it.");

    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 70,
            "range": 80
        ]),
        ([
            "probability": 35,
            "base damage": 130,
            "range": 120
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
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/ancestral-blessing.c",
            "name": "Ancestral Blessing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ])
    }));
    addSpecification("consumables", (["elder ward rune": 1]));
}
