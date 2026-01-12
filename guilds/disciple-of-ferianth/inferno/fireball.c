//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Storm");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of conjuring a ball of sacred fire that explodes on "
        "impact, engulfing all nearby enemies in divine flames.");
    addSpecification("usage summary", "A powerful area-of-effect fire attack");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/burning-hands.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 15
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 35,
            "range": 55
        ]),
        ([
            "probability": 30,
            "base damage": 55,
            "range": 75
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/fire-mastery.c",
            "name": "Fire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/inferno-potency.c",
            "name": "Inferno Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/divine-fire-potency.c",
            "name": "Divine Fire Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
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
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.75
        ])
    }));

    addSpecification("cooldown", 20);
    addSpecification("event handler", "fireballEvent");
    addSpecification("command template", "fireball [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## a roaring ball of sacred fire and "
        "##Infinitive::hurl## it at ##TargetName##, where it explodes "
        "in a burst of divine flame!");
}
