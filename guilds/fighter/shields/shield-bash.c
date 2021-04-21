//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    //addSpecification("modifiers", ({ 
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/under-cutting.c",
    //        "name": "under-cutting",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/reverse-cut.c",
    //        "name": "reverse-cut",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/double-back.c",
    //        "name": "double-back",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/riposte.c",
    //        "name": "riposte",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/reversing-the-blade.c",
    //        "name": "reversing-the-blade",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/over-cutting.c",
    //        "name": "over-cutting",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/cross-cutting.c",
    //        "name": "cross-slashing",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/dancing-blade.c",
    //        "name": "dancing-blade",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/hanging-cut.c",
    //        "name": "hanging-cut",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "research",
    //        "research item": "/guilds/fighter/shields/master-stroke.c",
    //        "name": "master-stroke",
    //        "formula": "multiplicative",
    //        "base value": 1,
    //        "rate": 1.5
    //    ]),
    //    ([
    //        "type": "offhand damage",
    //        "name" : "shield",
    //        "types" : ({ "shield" }),
    //        "formula" : "additive",
    //        "rate" : 1.5
    //    ]),
    //    ([
    //        "type": "skill",
    //        "name": "shield",
    //        "formula": "additive",
    //        "rate": 0.20
    //    ]),
    //    ([
    //        "type": "skill",
    //        "name": "anatomy and physiology",
    //        "formula": "additive",
    //        "rate": 0.10
    //    ]),
    //    ([
    //        "type": "skill",
    //        "name": "acrobatics",
    //        "formula": "additive",
    //        "rate": 0.05
    //    ]),
    //    ([
    //        "type": "skill",
    //        "name": "physics",
    //        "formula": "additive",
    //        "rate": 0.10
    //    ]),
    //    ([
    //        "type": "skill",
    //        "name": "mathematics",
    //        "formula": "additive",
    //        "rate": 0.10
    //    ]),
    //    ([
    //        "type": "attribute",
    //        "name": "dexterity",
    //        "formula": "additive",
    //        "rate": 0.25
    //    ]),
    //    ([
    //        "type": "attribute",
    //        "name": "strength",
    //        "formula": "additive",
    //        "rate": 0.25
    //    ]),
    //    ([
    //        "type": "attribute",
    //        "name": "wisdom",
    //        "formula": "additive",
    //        "rate": 0.15
    //    ]),
    //}));

    //addSpecification("stamina point cost", 50);
    //addSpecification("stamina point cost modifiers", ([
    //    "/guilds/fighter/shields/blademasters-reserve.c": 5,
    //    "/guilds/fighter/shields/blademasters-call.c": 5,
    //    "/guilds/fighter/shields/blademasters-might.c": 5,
    //    "/guilds/fighter/shields/blademasters-fury.c": 5
    //]));

    //addSpecification("cooldown", 30);
    //addSpecification("cooldown modifiers", ([
    //    "/guilds/fighter/shields/blademasters-boon.c": 5,
    //    "/guilds/fighter/shields/blademasters-speed.c": 5,
    //    "/guilds/fighter/shields/blademasters-endurance.c": 5,
    //    "/guilds/fighter/shields/blademasters-strength.c": 5,
    //]));

    addSpecification("event handler", "shieldBashEvent");
    addSpecification("command template", "shield bash [##Target##]");
    addSpecification("use ability message",  "##InitiatorName## "
        "##Infinitive::swing## ##InitiatorPossessive## "
        "##InitiatorWeapon::Offhand## at ##TargetName##.");
}
