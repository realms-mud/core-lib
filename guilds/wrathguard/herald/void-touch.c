//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "void touch");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Herald channels void energy "
        "through their touch, draining the target's vitality into the "
        "void.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 20);
    addSpecification("command template", "void touch ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::extend## a void-touched "
        "hand toward ##TargetName##.");
    addSpecification("damage type", "shadow");
    addSpecification("siphon hit points", ({
        ([
            "probability": 100,
            "base damage": 25,
            "range": 15
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/herald/herald-form.c",
            "name": "Herald Form",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/herald/shadow-bolt.c",
            "name": "Shadow Bolt",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
    addSpecification("limited by", ([
        "research active":
            "/guilds/wrathguard/herald/herald-form.c"
    ]));
    addPrerequisite("/guilds/wrathguard/herald/shadow-bolt.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 25
        ]));
}
