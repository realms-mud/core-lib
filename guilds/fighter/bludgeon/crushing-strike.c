//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crushing Strike");
    addSpecification("source", "fighter");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a blunt weapon technique that causes massive damage to "
        "an enemy.");

    addPrerequisite("/guilds/fighter/bludgeon/cudgel.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "mace", "hammer",
        "flail", "staff" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 29
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 100,
            "range": 200
        ]),
        ([
            "probability": 10,
            "base damage": 200,
            "range": 500
        ])
    }));
    addSpecification("damage stamina points", ({ ([
            "probability": 90,
            "base damage": 50,
            "range": 100
        ]),
        ([
            "probability": 10,
            "base damage": 100,
            "range": 200
        ])
    }));

    addSpecification("damage type", "bludgeon");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/under-striking.c",
            "name": "under-striking",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/reverse-bash.c",
            "name": "reverse-bash",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/redoubled-push.c",
            "name": "redoubled-push",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/unrelenting-strike.c",
            "name": "unrelenting-strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/reversing-the-swing.c",
            "name": "reversing-the-swing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/over-driving.c",
            "name": "over-driving",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/cross-driving.c",
            "name": "cross-driving",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/dancing-cudgel.c",
            "name": "dancing-cudgel",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/hanging-stroke.c",
            "name": "hanging-stroke",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/bludgeon/master-bludgeon.c",
            "name": "master-bludgeon",
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
            "name" : "blunt weapons",
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

    addSpecification("stamina point cost", 200);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/fighter/bludgeon/bludgeoners-reserve.c": 10,
        "/guilds/fighter/bludgeon/bludgeoners-call.c": 10,
        "/guilds/fighter/bludgeon/bludgeoners-might.c": 10,
        "/guilds/fighter/bludgeon/bludgeoners-fury.c": 10
    ]));

    addSpecification("cooldown", 100);
    addSpecification("cooldown group", "fighter weapon level 29");
    addSpecification("cooldown modifiers", ([
        "/guilds/fighter/bludgeon/bludgeoners-boon.c": 10,
        "/guilds/fighter/bludgeon/bludgeoners-speed.c": 10,
        "/guilds/fighter/bludgeon/bludgeoners-endurance.c": 10,
        "/guilds/fighter/bludgeon/bludgeoners-strength.c": 10,
    ]));

    addSpecification("event handler", "crushingStrikeEvent");
    addSpecification("command template", "crushing strike [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorName## "
        "##Infinitive::strike## ##InitiatorPossessive## "
        "##InitiatorWeapon## into ##TargetName## with deft skill.");
}
