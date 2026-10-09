//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Voice of the Dead");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels the voices of "
        "many ancestors simultaneously, dealing spiritual damage to all "
        "nearby enemies with a resonating cry.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 8]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-storm.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke voice of the dead");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the voices of the dead in a resonating cry that rattles all nearby foes.");

    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 18);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 50,
            "range": 55
        ]),
        ([
            "probability": 30,
            "base damage": 90,
            "range": 90
        ])
    }));

    addSpecification("modifiers", ({
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
            "rate": 1.15
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
