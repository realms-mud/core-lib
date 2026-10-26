//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sapping Palm");
    addSpecification("source", "monk");
    addSpecification("description",
        "The palm slips past the guard to trouble the quiet behind it. "
        "A jarring touch at a breathing point leaves the foe struggling "
        "to gather the inward strength they had held ready.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
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
    addPrerequisite("/guilds/monk/unarmed/driving-elbow.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/elbow-anatomy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 14);

    addSpecification("command template", "kata sapping palm at ##Target##");
    addSpecification("usage summary", "kata sapping palm at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## sapping palm against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "physical");
    addSpecification("damage spell points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":4
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"unarmed",
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
            "type":"research",
            "name":"meridian-lore",
            "research item":"/guilds/monk/unarmed/meridian-lore.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ]),
        ([
            "type":"skill",
            "name":"anatomy and physiology",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"skill",
            "name":"perception",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"magical essence",
            "formula":"additive",
            "rate":0.05
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
            "rate":0.1
        ]),
        ([
            "type":"research",
            "name":"Elbow Anatomy",
            "research item":"/guilds/monk/unarmed/elbow-anatomy.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Pulse Mapping",
            "research item":"/guilds/monk/unarmed/pulse-mapping.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Empty Hand Theory",
            "research item":"/guilds/monk/unarmed/empty-hand-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ])
    }));
}
