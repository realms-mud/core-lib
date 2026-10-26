//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Descending Shot");
    addSpecification("source", "monk");
    addSpecification("description",
        "Raise the bow into a steep, deliberate draw and release "
        "down through the opening below. The arrow falls upon "
        "the guard like a hawk stooping from its watch.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":42
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/draw-alignment.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 24);

    addSpecification("command template",
        "kata descending shot at ##Target##");
    addSpecification("usage summary", "kata descending shot at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## descending shot against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "arrow");
    addSpecification("consumables", ([
        "arrow":1
    ]));
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":26,
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
            "name":"Crosswind Geometry",
            "research item":"/guilds/monk/archery/crosswind-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
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
            "name":"falling-trajectory",
            "research item":"/guilds/monk/archery/falling-trajectory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ])
    }));
}
