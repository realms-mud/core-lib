//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "radiant mending surge");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels a massive "
        "surge of healing energy into a target, mending grievous "
        "wounds with the power of radiant conviction.");
    addPrerequisite("/guilds/phaedra/fidelity/sovereign-healer.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 59]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 35);
    addSpecification("command template", "radiant mending surge at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## a surge of radiant "
        "healing into ##TargetName##, mending wounds with blazing light.");
    addSpecification("increase hit points", ({
        ([
            "probability": 70,
            "base damage": 60,
            "range": 50
        ]),
        ([
            "probability": 30,
            "base damage": 90,
            "range": 70
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/sovereign-healer.c",
            "name": "Sovereign Healer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/restorative-aura.c",
            "name": "Restorative Aura",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/devoted-mastery.c",
            "name": "Devoted Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.60
        ])
    }));
}
