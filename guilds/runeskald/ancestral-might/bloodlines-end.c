//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bloodline's End");
    addSpecification("source", "runeskald");
    addSpecification("description", "The ultimate ancestral offensive: the "
        "runeskald collapses the spiritual power of their entire bloodline "
        "into a single cataclysmic attack that devastates all nearby foes.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 22]));
    addPrerequisite("/guilds/runeskald/ancestral-might/grave-tide.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestral-ascendance.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 30);
    addSpecification("command template", "invoke bloodline's end");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::collapse## the full power of their bloodline into one cataclysmic eruption.");

    addSpecification("spell point cost", 80);
    addSpecification("stamina point cost", 35);

    addSpecification("damage hit points", ({
        ([
            "probability": 55,
            "base damage": 150,
            "range": 170
        ]),
        ([
            "probability": 45,
            "base damage": 275,
            "range": 250
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
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/spirits-wrath-ii.c",
            "name": "spirits-wrath-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/spirits-reserve-ii.c",
            "name": "spirits-reserve-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/ancestral-resonance.c",
            "name": "Ancestral Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ])
    }));
    addSpecification("consumables", (["ancient ward rune": 1]));
}
