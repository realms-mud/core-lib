//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "strike of the founders");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels the "
        "undying courage of Phaedra's founding companions into "
        "a single transcendent strike. The blow carries the "
        "weight of every oath sworn in the Order's name.");
    addPrerequisite("/guilds/phaedra/courage/invincible-courage.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 65]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 35);
    addSpecification("command template",
        "strike of the founders at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## channel##InitiatorReflexive## the courage "
        "of Phaedra's founders, striking ##TargetName## with "
        "devastating force.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 55,
            "range": 45
        ]),
        ([
            "probability": 40,
            "base damage": 85,
            "range": 65
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "broad sword", "short sword" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/invincible-courage.c",
            "name": "Invincible Courage",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/founders-resolve.c",
            "name": "Founder's Resolve",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/dawns-judgment.c",
            "name": "Dawn's Judgment",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.25
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
            "rate": 0.32
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
            "rate": 0.70
        ])
    }));
}
