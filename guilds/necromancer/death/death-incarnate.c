//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Death Incarnate");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the death incarnate spell. The necromancer becomes "
        "a vessel for death itself, unleashing its full power on all "
        "nearby foes.");

    addPrerequisite("/guilds/necromancer/death/shadow-tempest.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 67
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 175,
            "range": 320
        ]),
        ([
            "probability": 20,
            "base damage": 350,
            "range": 640
        ])
    }));

    addSpecification("damage type", "shadow");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/void-vortex.c",
            "name": "Void Vortex",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "necromancer",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.025
        ]),
    }));

    addSpecification("spell point cost", 250);
    addSpecification("spell point cost modifiers", ([
        "/guilds/necromancer/death/deathweavers-reserve.c": 10,
        "/guilds/necromancer/death/deathweavers-call.c": 10,
        "/guilds/necromancer/death/deathweavers-might.c": 10,
        "/guilds/necromancer/death/deathweavers-fury.c": 10
    ]));

    addSpecification("cooldown", 180);
    addSpecification("cooldown modifiers", ([
        "/guilds/necromancer/death/deathweavers-boon.c": 10,
        "/guilds/necromancer/death/deathweavers-finesse.c": 10,
        "/guilds/necromancer/death/deathweavers-endurance.c": 10,
        "/guilds/necromancer/death/deathweavers-strength.c": 10,
    ]));

    addSpecification("event handler", "deathIncarnateEvent");
    addSpecification("command template", "death incarnate");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::become## a vessel of death incarnate, shadow "
        "and void ##Infinitive::erupt## from ##InitiatorPossessive## "
        "form to ##Infinitive::consume## the living around ##InitiatorObject##.");
}
