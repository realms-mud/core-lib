//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shield Bash");
    addSpecification("source", "fighter");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to use an equipped shield to hit a foe.");

    addPrerequisite("/guilds/fighter/shields/root.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "shield" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 3
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 15,
            "range": 15
        ]),
        ([
            "probability": 10,
            "base damage": 25,
            "range": 50
        ])
    }));

    addSpecification("damage type", "bludgeon");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/improvised-attack.c",
            "name": "Improvised Attack",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/reverse-sweep.c",
            "name": "Reverse Sweep",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/using-the-edge.c",
            "name": "Using the Edge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/breaking-through.c",
            "name": "Breaking Through",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/shield-thrusting.c",
            "name": "Shield Thrusting",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/crushing-drive.c",
            "name": "Crushing Drive",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/disruptive-striking.c",
            "name": "Disruptive Striking",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/edge-striking.c",
            "name": "Edge Striking",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/face-striking.c",
            "name": "Face Striking",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/shields/shield-mastery.c",
            "name": "Shield Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "offhand damage",
            "name" : "shield",
            "types" : ({ "shield" }),
            "formula" : "additive",
            "rate" : 1.5
        ]),
        ([
            "type": "skill",
            "name": "shield",
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
            "type": "skill",
            "name": "acrobatics",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.15
        ]),
    }));

    addSpecification("stamina point cost", 50);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/fighter/shields/shieldmasters-reserve.c": 5,
        "/guilds/fighter/shields/shieldmasters-call.c": 5,
        "/guilds/fighter/shields/shieldmasters-might.c": 5,
        "/guilds/fighter/shields/shieldmasters-fury.c": 5
    ]));

    addSpecification("cooldown", 30);
    addSpecification("cooldown modifiers", ([
        "/guilds/fighter/shields/shieldmasters-boon.c": 5,
        "/guilds/fighter/shields/shieldmasters-speed.c": 5,
        "/guilds/fighter/shields/shieldmasters-endurance.c": 5,
        "/guilds/fighter/shields/shieldmasters-strength.c": 5,
    ]));

    addSpecification("event handler", "shieldBashEvent");
    addSpecification("command template", "shield bash [##Target##]");
    addSpecification("use ability message",  "##InitiatorName## "
        "##Infinitive::swing## ##InitiatorPossessive## "
        "##InitiatorWeapon::Offhand## into ##TargetName##.");
}
