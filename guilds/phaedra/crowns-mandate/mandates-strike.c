//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "mandate's strike");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels the full "
        "authority of the Crown's Mandate into a single decisive "
        "strike, radiating with the good-aligned power of the Order.");
    addPrerequisite(
        "/guilds/phaedra/crowns-mandate/radiant-authority.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
          "value": "steward"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 20);
    addSpecification("command template", "mandates strike at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## channel##InitiatorReflexive## the authority "
        "of the Crown's Mandate, striking ##TargetName## with "
        "radiant force.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 30,
            "range": 25
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger",
        "broad sword" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/radiant-authority.c",
            "name": "Radiant Authority",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/phaedras-aegis.c",
            "name": "Phaedra's Aegis",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
