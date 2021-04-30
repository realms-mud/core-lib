//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cudgel");
    addSpecification("source", "fighter");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a blunt weapon technique that causes damage to "
        "an enemy.");

    addPrerequisite("/guilds/fighter/bludgeon/root.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "mace", "hammer",
        "flail", "staff" })]));

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
            "base damage": 10,
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
            "research item": "/guilds/fighter/bludgeon/under-striking.c",
            "name": "Under Striking",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/reverse-bash.c",
            "name": "Reverse Bash",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/redoubled-push.c",
            "name": "Redoubled Push",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/unrelenting-strike.c",
            "name": "Unrelenting Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/reversing-the-swing.c",
            "name": "Reversing the Swing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/over-driving.c",
            "name": "Over Driving",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/cross-driving.c",
            "name": "Cross Driving",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/dancing-cudgel.c",
            "name": "Dancing Cudgel",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/hanging-stroke.c",
            "name": "Hanging Stroke",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/master-bludgeon.c",
            "name": "Master Bludgeon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "deferred attack",
            "name": "deferred attack",
            "trait": "/guilds/fighter/techniques/calculated-attack.c",
            "formula": "multiplicative",
            "rate": 0.01
        ]),
        ([
            "type": "weapon damage",
            "name" : "blunt weapon",
            "types" : ({ "mace", "hammer", "flail", "staff" }),
            "formula" : "additive",
            "rate" : 0.75
        ]),
        ([
            "type":"highest skill",
            "name" : "blunt skills",
            "skills": ({ "mace", "hammer", "flail", "staff" }),
            "formula" : "additive",
            "rate" : 0.5
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
            "name": "dancing",
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
        "/guilds/fighter/bludgeon/bludgeoners-reserve.c": 5,
        "/guilds/fighter/bludgeon/bludgeoners-call.c": 5,
        "/guilds/fighter/bludgeon/bludgeoners-might.c": 5,
        "/guilds/fighter/bludgeon/bludgeoners-fury.c": 5
    ]));

    addSpecification("cooldown", 30);
    addSpecification("cooldown group", "fighter weapon level 3");
    addSpecification("cooldown modifiers", ([
        "/guilds/fighter/bludgeon/bludgeoners-boon.c": 5,
        "/guilds/fighter/bludgeon/bludgeoners-speed.c": 5,
        "/guilds/fighter/bludgeon/bludgeoners-endurance.c": 5,
        "/guilds/fighter/bludgeon/bludgeoners-strength.c": 5,
    ]));

    addSpecification("event handler", "cudgelEvent");
    addSpecification("command template", "cudgel [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorName## "
        "##Infinitive::cudgel## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## aggressively.");
}
