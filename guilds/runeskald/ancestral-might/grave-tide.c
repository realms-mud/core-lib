//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grave Tide");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald opens a temporary rift "
        "to the spirit world, releasing a tide of hungry ghosts that "
        "tears through everything nearby.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 16]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestral-nova.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-legion.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 40);
    addSpecification("command template", "invoke grave tide");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::tear## open a rift to the spirit world and a tide of grave-cold ghosts pours forth.");

    addSpecification("spell point cost", 60);
    addSpecification("stamina point cost", 25);

    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 110,
            "range": 120
        ]),
        ([
            "probability": 40,
            "base damage": 200,
            "range": 180
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
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/ancestral-resonance.c",
            "name": "Ancestral Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ])
    }));
    addSpecification("consumables", (["ancient ward rune": 1]));
}
