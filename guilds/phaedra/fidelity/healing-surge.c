//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "healing surge");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels a surge "
        "of restorative energy into a wounded ally, rapidly healing "
        "a significant portion of their injuries.");
    addPrerequisite("/guilds/phaedra/fidelity/mending-touch.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/fidelity/restorative-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 5]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 22);
    addSpecification("cooldown", 16);
    addSpecification("command template", "healing surge on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::send## a surge of "
        "restorative energy into ##TargetName##.");
    addSpecification("increase hit points", ({
        ([
            "probability": 100,
            "base damage": 22,
            "range": 20
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/restorative-knowledge.c",
            "name": "Restorative Knowledge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/fidelity/oath-of-protection.c",
            "name": "Oath of Protection",
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
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.40
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
            "rate": 0.40
        ])
    }));
}
