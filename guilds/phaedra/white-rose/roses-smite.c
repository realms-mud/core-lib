//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "rose's smite");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels the "
        "full meaning of the White Rose into a focused "
        "smite - radiant, precise, and carrying the "
        "authority of all four pillars combined.");
    addPrerequisite(
        "/guilds/phaedra/white-rose/thornwall.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
        "value": "steward"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 30);
    addSpecification("command template", "roses smite at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## channel##InitiatorReflexive## the power "
        "of the White Rose, striking ##TargetName## with "
        "radiant force.");
    addSpecification("damage type", "radiant");
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
        "hand and a half sword", "broad sword", "short sword" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/white-rose/thornwall.c",
            "name": "Thornwall",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/white-rose/roses-radiance.c",
            "name": "Rose's Radiance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/white-rose/white-rose-supremacy.c",
            "name": "White Rose Supremacy",
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
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
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
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.65
        ])
    }));
}
