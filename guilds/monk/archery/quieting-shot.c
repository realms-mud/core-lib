//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quieting Shot");
    addSpecification("source", "monk");
    addSpecification("description",
        "Loose into the space where your foe gathers thought "
        "and breath. The sudden threat breaks that inward "
        "rhythm, leaving intent scattered in its wake.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":50
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/draw-pressure-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 24);

    addSpecification("command template", "kata quieting shot at ##Target##");
    addSpecification("usage summary", "kata quieting shot at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## quieting shot against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "arrow");
    addSpecification("consumables", ([
        "arrow":1
    ]));
    addSpecification("damage spell points", ({
        ([
            "probability":100,
            "base damage":18,
            "range":3
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"meditation",
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
            "name":"Bow Breath Theory",
            "research item":"/guilds/monk/archery/bow-breath-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Draw Pressure Theory",
            "research item":"/guilds/monk/archery/draw-pressure-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Point of Release",
            "research item":"/guilds/monk/archery/point-of-release.c",
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
            "name":"wisdom",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"weapon damage",
            "name":"archery",
            "types":({ "bow" }),
            "formula":"additive",
            "rate":0.5
        ])
    }));
}
