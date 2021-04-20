//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gore");
    addSpecification("source", "fighter");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a gashing polearm technique that causes massive damage to "
        "an enemy.");

    addPrerequisite("/guilds/fighter/polearms/gash.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "pole arm" })]));

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

    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/forceful-thrust.c",
            "name": "forceful-thrust",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/fools-bayonet.c",
            "name": "fools-bayonet",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/hooking-thrust.c",
            "name": "hooking-thrust",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/perforation.c",
            "name": "perforation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/transfix.c",
            "name": "transfix",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/piercing-blow.c",
            "name": "piercing-blow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/penetration.c",
            "name": "penetration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/slicing-stroke.c",
            "name": "slicing-stroke",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/lunging-strike.c",
            "name": "lunging-strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/fighter/polearms/master-skewer.c",
            "name": "master-skewer",
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
            "name" : "polearm damage",
            "types" : ({ "pole arm" }),
            "formula" : "additive",
            "rate" : 0.75
        ]),
        ([
            "type": "skill",
            "name" : "pole arm",
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
        "/guilds/fighter/polearms/polemasters-reserve.c": 10,
        "/guilds/fighter/polearms/polemasters-call.c": 10,
        "/guilds/fighter/polearms/polemasters-might.c": 10,
        "/guilds/fighter/polearms/polemasters-fury.c": 10
    ]));

    addSpecification("cooldown", 100);
    addSpecification("cooldown group", "fighter weapon level 29");
    addSpecification("cooldown modifiers", ([
        "/guilds/fighter/polearms/polemasters-boon.c": 10,
        "/guilds/fighter/polearms/polemasters-speed.c": 10,
        "/guilds/fighter/polearms/polemasters-endurance.c": 10,
        "/guilds/fighter/polearms/polemasters-strength.c": 10,
    ]));

    addSpecification("event handler", "goreEvent");
    addSpecification("command template", "gore [##Target##]");
    addSpecification("use ability message",  "##InitiatorName## "
        "violently ##Infinitive::impale## ##InitiatorPossessive## "
        "##InitiatorWeapon## into ##TargetName## with deft skill.");
}
