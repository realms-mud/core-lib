//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Breath Shear");
    addSpecification("source", "monk");
    addSpecification("description",
        "One edge draws the eye while the other crowds the breath. "
        "The opponent's inward composure frays as the paired "
        "blades keep asking incompatible questions.");

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
        "value":18
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "student", "disciple", "adept", "senior disciple",
            "master candidate", "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/paired-swords/paired-pressure.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 16);

    addSpecification("command template", "kata breath shear at ##Target##");
    addSpecification("usage summary", "kata breath shear at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## breath shear against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage spell points", ({
        ([
            "probability":100,
            "base damage":12,
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
            "name":"wisdom",
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
            "name":"Paired Breath Theory",
            "research item":"/guilds/monk/paired-swords/paired-breath-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"perception",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"anatomy and physiology",
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
            "name":"intelligence",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Linked Lines",
            "research item":"/guilds/monk/paired-swords/linked-lines.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
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

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/paired-swords/paired-breath-economy.c":2
    ]));
}
