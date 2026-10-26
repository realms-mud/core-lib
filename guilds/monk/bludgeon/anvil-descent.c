//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Anvil Descent");
    addSpecification("source", "monk");
    addSpecification("description",
        "Raise the hammer with the patience of a smith judging the "
        "heat of iron. Its descending head drives through the guard "
        "with the stern finality of a forging stroke.");

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
        "value":68
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
    addPrerequisite("/guilds/monk/bludgeon/anvil-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 19);
    addSpecification("cooldown", 26);

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/hammer-return.c":1
    ]));

    addSpecification("command template", "kata anvil descent at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## deliver##InitiatorReflexive## an anvil descent to "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":16,
            "range":5
        ])
    }));
    addSpecification("damage stamina points", ({
        ([
            "probability":100,
            "base damage":6,
            "range":2
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"hammer",
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
            "type":"weapon damage",
            "name":"hammer",
            "types":({ "hammer" }),
            "formula":"additive",
            "rate":0.35
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"research",
            "name":"anvil geometry",
            "research item":"/guilds/monk/bludgeon/anvil-geometry.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));
}
