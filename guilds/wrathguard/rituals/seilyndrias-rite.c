//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "seilyndria's rite");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Wrathguard performs the rite of the "
        "Dark Queen herself, a working of terrifying power that channels "
        "Seilyndria's divine annihilation through the caster.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 128);
    addSpecification("cooldown", 30);
    addSpecification("command template", "seilyndrias rite on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::perform## Seilyndria's rite "
        "against ##TargetName##.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 180,
            "range": 128
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/rituals/rite-of-ruin.c",
            "name": "Rite of Ruin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/rituals/void-ritual.c",
            "name": "Void Ritual",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "blood",
            "formula": "additive",
            "rate": 0.25
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
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 2.20
        ])
    }));
    addPrerequisite("/guilds/wrathguard/rituals/void-ritual.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 65
        ]));
}
