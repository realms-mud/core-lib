//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "avatar of phaedra");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "For a brief moment the companion "
        "channels the full avatar-state of Phaedra's founding "
        "ideal, releasing a torrent of radiant sovereign force "
        "that embodies all four pillars at once.");
    addPrerequisite(
        "/guilds/phaedra/crowns-mandate/indestructible-guard.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
        "value": "high companion"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);
    addSpecification("cooldown", 45);
    addSpecification("command template",
        "avatar of phaedra at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## become##InitiatorReflexive## a blazing "
        "avatar of Phaedra's ideal, unleashing devastating "
        "radiant force upon ##TargetName##.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 50,
            "base damage": 75,
            "range": 65
        ]),
        ([
            "probability": 50,
            "base damage": 115,
            "range": 85
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/indestructible-guard.c",
            "name": "Indestructible Guard",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/sovereigns-will.c",
            "name": "Sovereign's Will",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/phaedra/crowns-mandate/mandate-supreme.c",
            "name": "Mandate Supreme",
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
