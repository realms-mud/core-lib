//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Claw Check");
    addSpecification("source", "monk");
    addSpecification("description",
        "Present the talons inside the foe's reach and make them "
        "wrench their guard back into place. The cramped response "
        "leaves less breath for whatever they meant to do next.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":5
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/claw-footwork.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 12);

    addSpecification("command template", "kata claw check at ##Target##");
    addSpecification("usage summary", "kata claw check at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## claw check against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "thrust");
    addSpecification("damage stamina points", ({
        ([
            "probability":100,
            "base damage":10,
            "range":2
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"dagger",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"weapon damage",
            "name":"claw",
            "types":({ "dagger" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"research",
            "name":"Claw Leverage",
            "research item":"/guilds/monk/claw/claw-leverage.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"parry",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"physics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Rake Geometry",
            "research item":"/guilds/monk/claw/rake-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Grip Geometry",
            "research item":"/guilds/monk/claw/grip-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));
}
