//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Close Circle");
    addSpecification("source", "monk");
    addSpecification("description",
        "You step inside the adversary's comfortable measure and "
        "fold both blades around the guard. Their arms must labor "
        "to answer the narrowing circle of steel.");

    addSpecification("limited by", ([
        "equipment":({
            ([
                "blueprint":"katana",
                "slot":"wielded primary"
            ]),
            ([
                "blueprint":"wakisashi",
                "slot":"wielded offhand"
            ])
        })
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
    addPrerequisite("/guilds/monk/paired-swords/paired-readiness.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 20);

    addSpecification("command template", "kata close circle at ##Target##");
    addSpecification("usage summary", "kata close circle at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## close circle against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage stamina points", ({
        ([
            "probability":100,
            "base damage":24,
            "range":3
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"hand and a half sword",
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
            "name":"paired-swords",
            "types":({ "hand and a half sword" }),
            "formula":"additive",
            "rate":0.35
        ]),
        ([
            "type":"offhand damage",
            "name":"wakisashi",
            "types":({ "short sword" }),
            "formula":"additive",
            "rate":0.2
        ]),
        ([
            "type":"skill",
            "name":"dodge",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"parry",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
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
            "name":"Binding Lines",
            "research item":"/guilds/monk/paired-swords/binding-lines.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Paired Point Theory",
            "research item":"/guilds/monk/paired-swords/paired-point-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ])
    }));
}
