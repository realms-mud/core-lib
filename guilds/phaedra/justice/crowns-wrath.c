//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "crown's wrath");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The wrath of the Crown descends "
        "upon the target - a devastating strike carrying the "
        "full judicial authority and good-aligned might "
        "of the Order of Phaedra.");
    addPrerequisite("/guilds/phaedra/justice/eternal-justice.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 51]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 38);
    addSpecification("command template", "crowns wrath at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::call## the wrath of the Crown "
        "upon ##TargetName##, justice and radiant force descending as one.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 55,
            "range": 50
        ]),
        ([
            "probability": 35,
            "base damage": 85,
            "range": 65
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/absolute-authority.c",
            "name": "Absolute Authority",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/eternal-justice.c",
            "name": "Eternal Justice",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/condemning-light.c",
            "name": "Condemning Light",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.32
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.65
        ])
    }));
}
