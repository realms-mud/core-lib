//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sickle Point");
    addSpecification("source", "monk");
    addSpecification("description",
        "Turn the wrist so the sickle's tip leads instead of its edge. "
        "A compact step carries that narrow promise through the "
        "opening left by a guard expecting another curved draw.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
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
    addPrerequisite("/guilds/monk/kama/sickle-readiness.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 18);

    addSpecification("command template", "kata sickle point at ##Target##");
    addSpecification("usage summary", "kata sickle point at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## sickle point against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":20,
            "range":2
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"short sword",
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
            "name":"kama",
            "types":({ "short sword" }),
            "formula":"additive",
            "rate":0.5
        ]),
        ([
            "type":"research",
            "name":"Sickle Point Theory",
            "research item":"/guilds/monk/kama/sickle-point-theory.c",
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
            "name":"strength",
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
            "name":"Binding Geometry",
            "research item":"/guilds/monk/kama/binding-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Crescent Geometry",
            "research item":"/guilds/monk/kama/crescent-geometry.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ])
    }));

    addSpecification("damage type", "thrust");
}
