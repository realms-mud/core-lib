//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rising Talon");
    addSpecification("source", "monk");
    addSpecification("description",
        "Sink beneath the foe's guarding arm and rise with the "
        "talons leading. The upward thrust carries the legs' "
        "stored force into a seam hidden from a level approach.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":43
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/crossing-talons.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 18);

    addSpecification("command template", "kata rising talon at ##Target##");
    addSpecification("usage summary", "kata rising talon at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## rising talon against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "thrust");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":22,
            "range":3
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
            "name":"Rising Talon Theory",
            "research item":"/guilds/monk/claw/rising-talon-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"physics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"dodge",
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
            "name":"Crossing Talons",
            "research item":"/guilds/monk/claw/crossing-talons.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Rake Geometry",
            "research item":"/guilds/monk/claw/rake-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));
}
