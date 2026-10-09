//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancestor's Judgment");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald calls down the judgment "
        "of their ancestors upon a foe, dealing heavy spiritual damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 6]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-bolt.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke ancestor's judgment ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::call## down the judgment of the ancestors upon ##TargetName##.");

    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 42,
            "range": 48
        ]),
        ([
            "probability": 30,
            "base damage": 78,
            "range": 75
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.08
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
