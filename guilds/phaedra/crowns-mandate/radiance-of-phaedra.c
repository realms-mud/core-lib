//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "radiance of phaedra");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The First Companion calls upon "
        "the full legacy of Phaedra herself, releasing a burst "
        "of radiant, good-aligned energy that burns away "
        "evil and carries the weight of the Order's eternal oath.");
    addPrerequisite(
        "/guilds/phaedra/crowns-mandate/crowns-champion.c",
        (["type": "research"]));
    addPrerequisite(
        "/guilds/phaedra/crowns-mandate/transcendent-guard.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
          "value": "first companion"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);
    addSpecification("cooldown", 45);
    addSpecification("command template",
        "radiance of phaedra at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## invoke##InitiatorReflexive## the radiance "
        "of Phaedra, unleashing a blinding torrent of holy power "
        "upon ##TargetName##.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 50,
            "base damage": 70,
            "range": 60
        ]),
        ([
            "probability": 50,
            "base damage": 110,
            "range": 80
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/crowns-champion.c",
            "name": "Crown's Champion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/radiant-authority.c",
            "name": "Radiant Authority",
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
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.75
        ])
    }));
}
