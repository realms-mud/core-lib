//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "good word");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels a potent "
        "restorative invocation infused with good-aligned energy, "
        "healing an ally with the pure light of the Order's ideals.");
    addPrerequisite("/guilds/phaedra/stewardship/sustaining-light.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/stewardship/wardens-lore.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 21]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 22);
    addSpecification("command template", "good word on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## a word of pure good, "
        "suffusing ##TargetName## with renewing light.");
    addSpecification("increase hit points", ({
        ([
            "probability": 90,
            "base damage": 30,
            "range": 28
        ]),
        ([
            "probability": 10,
            "base damage": 50,
            "range": 35
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/stewardship/wardens-lore.c",
            "name": "Warden's Lore",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/stewardship/restorative-presence.c",
            "name": "Restorative Presence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.45
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
