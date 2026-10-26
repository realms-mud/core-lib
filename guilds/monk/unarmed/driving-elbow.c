//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Driving Elbow");
    addSpecification("source", "monk");
    addSpecification("description",
        "Turn the hip through a space too narrow for a fist. The elbow "
        "follows like the head of a ram, carrying the weight of your "
        "stance into the opening beside the guard.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":8
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/hand-alignment.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 10);

    addSpecification("command template", "kata driving elbow at ##Target##");
    addSpecification("usage summary", "kata driving elbow at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## driving elbow against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "physical");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":16,
            "range":0
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
            "name":"elbow-anatomy",
            "research item":"/guilds/monk/unarmed/elbow-anatomy.c",
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
            "name":"physics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
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
            "name":"Fist Compression",
            "research item":"/guilds/monk/unarmed/fist-compression.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Grappling Mechanics",
            "research item":"/guilds/monk/unarmed/grappling-mechanics.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Empty Hand Theory",
            "research item":"/guilds/monk/unarmed/empty-hand-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ])
    }));
}
