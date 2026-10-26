//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Drawn Circle");
    addSpecification("source", "monk");
    addSpecification("description",
        "The katana sweeps around your turning body, its curve closing "
        "like a brushstroke around the adversary before you.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":40
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/rising-cut.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/rising-lines.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 12);

    addSpecification("command template", "kata drawn circle at ##Target##");
    addSpecification("usage summary", "kata drawn circle at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## drawn circle against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":18,
            "range":7
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"tactics",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"dodge",
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
            "name":"wisdom",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Rising Lines",
            "research item":"/guilds/monk/katana/rising-lines.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Point Alignment",
            "research item":"/guilds/monk/katana/point-alignment.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"skill",
            "name":"hand and a half sword",
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
            "type":"weapon damage",
            "name":"katana",
            "types":({ "hand and a half sword" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"research",
            "name":"circular-mechanics",
            "research item":"/guilds/monk/katana/circular-mechanics.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ])
    }));
}
