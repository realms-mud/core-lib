//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Measured Draw");
    addSpecification("source", "monk");
    addSpecification("description",
        "Draw until breath, string, and sight meet in quiet "
        "agreement. Release without snatching at the moment, "
        "then follow the arrow's departure with a steady hand.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":1
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/root.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 14);

    addSpecification("command template", "kata measured draw at ##Target##");
    addSpecification("usage summary", "kata measured draw at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## measured draw against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "arrow");
    addSpecification("consumables", ([
        "arrow":1
    ]));
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":14,
            "range":0
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
            "name":"perception",
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
            "name":"Bow Leverage",
            "research item":"/guilds/monk/archery/bow-leverage.c",
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
            "name":"draw-geometry",
            "research item":"/guilds/monk/archery/draw-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ])
    }));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/archery/draw-economy.c":2
    ]));
}
