//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "judgment of phaedra");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels the full "
        "judicial authority of the Order in a powerful strike that "
        "brings the light of righteous judgment upon an enemy.");
    addPrerequisite("/guilds/phaedra/justice/word-of-binding.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/justice/crowns-mandate-active.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 17]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 32);
    addSpecification("cooldown", 20);
    addSpecification("command template",
        "judgment of phaedra at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::bring## the Judgment of Phaedra "
        "down upon ##TargetName## in a burst of righteous light.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 85,
            "base damage": 25,
            "range": 25
        ]),
        ([
            "probability": 15,
            "base damage": 42,
            "range": 30
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/justices-edge.c",
            "name": "Justice's Edge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/crowns-mandate-active.c",
            "name": "Crown's Mandate",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/gavel-of-the-crown.c",
            "name": "Gavel of the Crown",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.18
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
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
