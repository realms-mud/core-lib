//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Barrage");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sends a barrage of "
        "ancestral spirits against multiple nearby enemies, dealing "
        "spiritual damage to all of them.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 4]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestors-rebuke.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke spirit barrage");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::send## a barrage of ancestor spirits howling at all nearby foes.");

    addSpecification("spell point cost", 28);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 22,
            "range": 22
        ]),
        ([
            "probability": 25,
            "base damage": 42,
            "range": 40
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.07
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
