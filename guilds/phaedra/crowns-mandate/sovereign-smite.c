//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "sovereign smite");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion brings all four "
        "pillars to bear in a single devastating smite, channeling "
        "the full sovereign power of the Order through their blade.");
    addPrerequisite(
        "/guilds/phaedra/crowns-mandate/masterful-blade.c",
        (["type": "research"]));
    addPrerequisite(
        "/guilds/phaedra/crowns-mandate/high-companions-bearing.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
          "value": "high companion"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 30);
    addSpecification("command template", "sovereign smite at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## bring##InitiatorReflexive## the full "
        "sovereign power of the Order down upon ##TargetName##.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 50,
            "range": 40
        ]),
        ([
            "probability": 40,
            "base damage": 75,
            "range": 55
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "broad sword" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/masterful-blade.c",
            "name": "Masterful Blade",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/crowns-light.c",
            "name": "Crown's Light",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/radiant-authority.c",
            "name": "Radiant Authority",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.60
        ])
    }));
}
