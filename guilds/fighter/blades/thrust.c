//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Thrust");
    addSpecification("source", "fighter");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a thrusting blade technique that causes damage to "
        "an enemy.");

    addPrerequisite("guilds/fighter/blades/root.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "long sword",
        "hand and a half sword", "two-handed sword", "dagger", 
        "short sword", })]));

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

    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/under-cutting.c",
            "name": "under-cutting",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/reverse-cut.c",
            "name": "reverse-cut",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/double-back.c",
            "name": "double-back",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/riposte.c",
            "name": "riposte",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/reversing-the-blade.c",
            "name": "reversing-the-blade",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/over-cutting.c",
            "name": "over-cutting",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/cross-cutting.c",
            "name": "cross-slashing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/dancing-blade.c",
            "name": "dancing-blade",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/hanging-cut.c",
            "name": "hanging-cut",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/fighter/blades/master-stroke.c",
            "name": "master-stroke",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "deferred attack",
            "name": "deferred attack",
            "trait": "guilds/fighter/blades/calculated-attack.c",
            "formula": "multiplicative",
            "rate": 0.01
        ]),
        ([
            "type": "weapon damage",
            "name" : "sword",
            "types" : ({ "long sword", "hand and a half sword", 
                "two-handed sword", "dagger", "short sword" }),
            "formula" : "additive",
            "rate" : 0.75
        ]),
        ([
            "type":"highest skill",
            "name" : "sword skills",
            "skills": ({ "long sword", "hand and a half sword", 
                "two-handed sword", "dagger", "short sword" }),
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
        "guilds/fighter/blades/blademasters-reserve.c": 5,
        "guilds/fighter/blades/blademasters-call.c": 5,
        "guilds/fighter/blades/blademasters-might.c": 5,
        "guilds/fighter/blades/blademasters-fury.c": 5
    ]));

    addSpecification("cooldown", 30);
    addSpecification("cooldown modifiers", ([
        "guilds/fighter/blades/blademasters-boon.c": 5,
        "guilds/fighter/blades/blademasters-speed.c": 5,
        "guilds/fighter/blades/blademasters-endurance.c": 5,
        "guilds/fighter/blades/blademasters-strength.c": 5,
    ]));

    addSpecification("event handler", "thrustEvent");
    addSpecification("command template", "thrust [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::thrust## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## aggressively.");
}
