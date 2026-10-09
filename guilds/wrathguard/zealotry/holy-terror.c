//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "holy terror");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Zealot becomes a vessel of "
        "holy terror, unleashing a torrent of divine magical force that "
        "shatters resolve and flesh alike.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 82);
    addSpecification("cooldown", 20);
    addSpecification("command template", "holy terror at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::become## holy terror "
        "incarnate against ##TargetName##.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 100,
            "range": 72
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/zealotry/righteous-immolation.c",
            "name": "Righteous Immolation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.08
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.40
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
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 1.80
        ])
    }));
    addPrerequisite("/guilds/wrathguard/zealotry/righteous-immolation.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 53
        ]));
}