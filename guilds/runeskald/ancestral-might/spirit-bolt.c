//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Bolt");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald hurls a bolt of condensed "
        "ancestral energy at a foe, dealing solid spiritual damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 3]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-touch.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke spirit bolt ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hurl## a bolt of condensed ancestral energy at ##TargetName##.");

    addSpecification("spell point cost", 22);
    addSpecification("stamina point cost", 8);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 28,
            "range": 30
        ]),
        ([
            "probability": 25,
            "base damage": 52,
            "range": 50
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
