//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Companion Thrust");
    addSpecification("source", "monk");
    addSpecification("description",
        "The longer edge shelters the shorter point as you close. "
        "A spare turn of the offhand sends the wakizashi down the "
        "thin lane hidden beside the katana.");

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
        "value":38
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/paired-swords/paired-footwork.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 16);

    addSpecification("command template",
        "kata companion thrust at ##Target##");
    addSpecification("usage summary", "kata companion thrust at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## companion thrust against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":18,
            "range":2
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
            "type":"research",
            "name":"Paired Point Theory",
            "research item":"/guilds/monk/paired-swords/paired-point-theory.c",
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
            "name":"perception",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Companion Leverage",
            "research item":"/guilds/monk/paired-swords/companion-leverage.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Opening Geometry",
            "research item":"/guilds/monk/paired-swords/opening-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));

    addSpecification("damage type", "thrust");
}
