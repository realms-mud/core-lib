//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chop");
    addSpecification("source", "fighter");
    addSpecification("description", "This research provides the user with the "
        "knowledge of an axe chopping technique that causes damage to "
        "an enemy.");

    addPrerequisite("/guilds/fighter/axes/root.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "axe" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 1
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 5,
            "range": 10
        ]),
        ([
            "probability": 10,
            "base damage": 15,
            "range": 30
        ])
    }));

    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/strike-the-blood.c",
            "name": "strike-the-blood",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/fools-strike.c",
            "name": "fools-strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/hooking-strike.c",
            "name": "hooking-strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/horn-thrust.c",
            "name": "horn-thrust",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/haft-strike.c",
            "name": "haft-strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/arresting-blow.c",
            "name": "arresting-blow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/arc-strike.c",
            "name": "arc-strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/broad-stroke.c",
            "name": "broad-stroke",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/uplifting-sweep.c",
            "name": "uplifting-sweep",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/axes/master-chop.c",
            "name": "master-chop",
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
            "name" : "axe damage",
            "types" : ({ "axe" }),
            "formula" : "additive",
            "rate" : 0.75
        ]),
        ([
            "type": "skill",
            "name" : "axe",
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

    addSpecification("stamina point cost", 30);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/fighter/axes/axemasters-reserve.c": 5,
        "/guilds/fighter/axes/axemasters-call.c": 5,
        "/guilds/fighter/axes/axemasters-might.c": 5,
        "/guilds/fighter/axes/axemasters-fury.c": 5
    ]));

    addSpecification("cooldown", 25);
    addSpecification("cooldown group", "fighter weapon level 1");
    addSpecification("cooldown modifiers", ([
        "/guilds/fighter/axes/axemasters-boon.c": 5,
        "/guilds/fighter/axes/axemasters-speed.c": 5,
        "/guilds/fighter/axes/axemasters-endurance.c": 5,
        "/guilds/fighter/axes/axemasters-strength.c": 5,
    ]));

    addSpecification("event handler", "chopEvent");
    addSpecification("command template", "chop [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::chop## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## in a relentless onslaught.");
}