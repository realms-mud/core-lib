//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Volley");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sends a rapid barrage of "
        "spirit strikes at a single target, each guided by an ancestral "
        "warrior's skill.");

    addPrerequisite("/guilds/runeskald/spirit-war/spirit-war-mastery.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke spirit volley ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a rapid storm of spirit-guided strikes at ##TargetName##.");

    addSpecification("spell point cost", 55);
    addSpecification("stamina point cost", 18);

    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 35,
            "range": 35
        ]),
        ([
            "probability": 40,
            "base damage": 70,
            "range": 45
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "strength",
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
