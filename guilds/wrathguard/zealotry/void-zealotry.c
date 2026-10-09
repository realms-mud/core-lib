//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "void zealotry");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Zealot's faith reaches into the "
        "void itself, pulling annihilating nothingness through their "
        "devotion to deal catastrophic magical damage.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 108);
    addSpecification("cooldown", 24);
    addSpecification("command template", "void zealotry at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::reach## into the void "
        "with zealous faith against ##TargetName##.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 148,
            "range": 106
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/zealotry/immolation-of-faith.c",
            "name": "Immolation of Faith",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.45
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 2.10
        ])
    }));
    addPrerequisite("/guilds/wrathguard/zealotry/immolation-of-faith.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 61
        ]));
}