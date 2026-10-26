//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burdening Blow");
    addSpecification("source", "monk");
    addSpecification("description",
        "Lay the hammer's weight upon a braced defense and follow "
        "through with patient pressure. Your opponent must bear "
        "that burden in their shoulders and their breath.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":52
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/hammer-return.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 17);

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/hammer-return.c":1
    ]));

    addSpecification("command template", "kata burdening blow at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## place##InitiatorReflexive## a burdening blow on "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage stamina points", ({
        ([
            "probability":100,
            "base damage":17,
            "range":5
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"tactics",
            "formula":"additive",
            "rate":0.15
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
            "name":"wisdom",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Leverage Study",
            "research item":"/guilds/monk/bludgeon/leverage-study.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Momentum Mastery",
            "research item":"/guilds/monk/bludgeon/momentum-mastery.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Anvil Geometry",
            "research item":"/guilds/monk/bludgeon/anvil-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"skill",
            "name":"hammer",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.15
        ])
    }));
}
