//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "radiant mending");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels radiant "
        "healing energy into a wounded ally, suffusing their wounds "
        "with good-aligned light that rapidly restores their vitality.");
    addPrerequisite("/guilds/phaedra/fidelity/healing-word.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/fidelity/devoted-healer.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 21]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 24);
    addSpecification("command template", "radiant mending on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## radiant healing into "
        "##TargetName##, suffusing their wounds with golden light.");
    addSpecification("increase hit points", ({
        ([
            "probability": 85,
            "base damage": 38,
            "range": 32
        ]),
        ([
            "probability": 15,
            "base damage": 60,
            "range": 40
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/font-of-healing.c",
            "name": "Font of Healing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/devoted-healer.c",
            "name": "Devoted Healer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/restorative-mastery.c",
            "name": "Restorative Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.35
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
