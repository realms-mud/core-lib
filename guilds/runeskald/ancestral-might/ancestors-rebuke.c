//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancestor's Rebuke");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald directs the displeasure "
        "of an ancestor spirit against a foe, dealing moderate spiritual "
        "damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 2]));
    addPrerequisite("/guilds/runeskald/ancestral-might/ancestor-lore.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke ancestor's rebuke ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::direct## the cold rebuke of an ancestor spirit at ##TargetName##.");

    addSpecification("spell point cost", 20);
    addSpecification("stamina point cost", 8);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 22,
            "range": 25
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
            "rate": 0.06
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
