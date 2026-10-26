//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quiet Rake");
    addSpecification("source", "monk");
    addSpecification("description",
        "Beneath the noise of the exchange, the talons make a "
        "small intrusion at a breathing point. The foe's inward "
        "poise falters before they understand what your hand has done.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":47
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/grip-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 22);

    addSpecification("command template", "kata quiet rake at ##Target##");
    addSpecification("usage summary", "kata quiet rake at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## quiet rake against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "thrust");
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
            "name":"dagger",
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
            "name":"claw",
            "types":({ "dagger" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"skill",
            "name":"perception",
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
            "name":"intelligence",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Claw Breath Theory",
            "research item":"/guilds/monk/claw/claw-breath-theory.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Grip Geometry",
            "research item":"/guilds/monk/claw/grip-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ])
    }));
}
