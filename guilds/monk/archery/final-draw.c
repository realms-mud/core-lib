//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Final Draw");
    addSpecification("source", "monk");
    addSpecification("description",
        "Settle every breath and motion behind a final, unhurried "
        "draw. The string parts from your fingers with the "
        "solemn certainty of a decision that cannot be recalled.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":64
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "master candidate",
        "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/archers-mastery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 24);
    addSpecification("cooldown", 30);

    addSpecification("command template", "kata final draw at ##Target##");
    addSpecification("usage summary", "kata final draw at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## final draw against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "arrow");
    addSpecification("consumables", ([
        "arrow":1
    ]));
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":36,
            "range":3
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"physics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"tactics",
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
            "name":"wisdom",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Draw Geometry",
            "research item":"/guilds/monk/archery/draw-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Point of Release",
            "research item":"/guilds/monk/archery/point-of-release.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"skill",
            "name":"bow",
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
            "name":"archery",
            "types":({ "bow" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"research",
            "name":"final-trajectory",
            "research item":"/guilds/monk/archery/final-trajectory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ])
    }));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/archery/final-draw-economy.c":3
    ]));
}
