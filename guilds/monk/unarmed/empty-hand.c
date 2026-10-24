//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Empty Hand");
    addSpecification("source", "monk");
    addSpecification("description",
        "A high-commitment finishing strike consumes sixteen stamina before "
        "efficiency training.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":58
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/hammer-fist.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/fist-compression.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 18);

    addSpecification("command template", "kata empty hand at ##Target##");
    addSpecification("usage summary", "kata empty hand at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## empty hand against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "physical");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":30,
            "range":6
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"unarmed",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"research",
            "name":"empty-hand-theory",
            "research item":"/guilds/monk/unarmed/empty-hand-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"anatomy and physiology",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"acrobatics",
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
            "name":"dexterity",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"research",
            "name":"Fist Compression",
            "research item":"/guilds/monk/unarmed/fist-compression.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"research",
            "name":"Elbow Anatomy",
            "research item":"/guilds/monk/unarmed/elbow-anatomy.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Heel Trajectory",
            "research item":"/guilds/monk/unarmed/heel-trajectory.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/unarmed/finishing-economy.c":2
    ]));
}
