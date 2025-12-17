//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Overwhelming Presence");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of projecting an overwhelming psychic presence that "
        "crushes the targets mental defenses through sheer force of will. "
        "It can only be used as part of a combination attack.");
    addSpecification("usage summary", "An intensity modifier that crushes "
        "defenses with psychic presence");

    addPrerequisite("/guilds/oneiromancer/projection-methods/resonant-frequency.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 45,
            "range": 90
        ]),
        ([
            "probability": 30,
            "base damage": 90,
            "range": 180
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type":"attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 14);
    addSpecification("event handler", "overwhelmingPresenceEvent");

    addSpecification("use combination message", "##Infinitive::project## "
        "an overwhelming psychic presence");
}
