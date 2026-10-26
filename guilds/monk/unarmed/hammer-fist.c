//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hammer Fist");
    addSpecification("source", "monk");
    addSpecification("description",
        "The closed hand falls with the blunt certainty of a smith's "
        "hammer. Your knees sink beneath it, driving the descending "
        "edge of the fist through the foe's sheltering arms.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":30
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/grounded-base.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 14);

    addSpecification("command template", "kata hammer fist at ##Target##");
    addSpecification("usage summary", "kata hammer fist at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## hammer fist against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "physical");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":24,
            "range":2
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
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"research",
            "name":"fist-compression",
            "research item":"/guilds/monk/unarmed/fist-compression.c",
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
            "name":"physics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"dexterity",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
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
            "name":"Grappling Mechanics",
            "research item":"/guilds/monk/unarmed/grappling-mechanics.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Empty Hand Theory",
            "research item":"/guilds/monk/unarmed/empty-hand-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ])
    }));
}
