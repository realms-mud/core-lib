//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Returning Cut");
    addSpecification("source", "monk");
    addSpecification("description",
        "The wakizashi receives the threat while the katana "
        "turns homeward. Behind that brief shelter, the long "
        "edge returns along a line the opponent has left bare.");

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
        "value":60
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/paired-swords/crossing-cut.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/paired-swords/opening-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 22);

    addSpecification("command template", "kata returning cut at ##Target##");
    addSpecification("usage summary", "kata returning cut at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## returning cut against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
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
            "name":"parry",
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
            "name":"wisdom",
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
            "name":"Opening Geometry",
            "research item":"/guilds/monk/paired-swords/opening-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Crossing Lines",
            "research item":"/guilds/monk/paired-swords/crossing-lines.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/paired-swords/paired-return-rhythm.c":4
    ]));
}
