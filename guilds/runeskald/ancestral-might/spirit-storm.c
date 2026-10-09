//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Storm");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald unleashes a storm of "
        "ancestor spirits that tears through all nearby enemies with "
        "spiritual energy.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 7]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-barrage.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke spirit storm");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a howling storm of ancestor spirits that tears through the area.");

    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 38,
            "range": 40
        ]),
        ([
            "probability": 30,
            "base damage": 70,
            "range": 68
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
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
