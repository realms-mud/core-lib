//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "crown of thorns");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion brings down a "
        "crown of radiant thorns upon their target - an "
        "ability that combines the White Rose's beauty "
        "with its lethal, piercing edge.");
    addPrerequisite(
        "/guilds/phaedra/white-rose/undying-rose.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
        "value": "high companion"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 35);
    addSpecification("command template", "crown of thorns at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## summon##InitiatorReflexive## a crown of "
        "radiant thorns, driving them into ##TargetName##.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 55,
            "base damage": 60,
            "range": 50
        ]),
        ([
            "probability": 45,
            "base damage": 90,
            "range": 65
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/white-rose/undying-rose.c",
            "name": "Undying Rose",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.28
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/white-rose/rose-champion.c",
            "name": "Rose Champion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.22
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/white-rose/roses-radiance.c",
            "name": "Rose's Radiance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.18
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
            "rate": 0.22
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.68
        ])
    }));
}
