//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Taxing Contact");
    addSpecification("source", "monk");
    addSpecification("description",
        "Drive the mace into a guarded line and stay with "
        "the contact long enough to make its weight felt. "
        "The defender must labor to hold against the stubborn head.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":48
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/mace-recovery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 11);
    addSpecification("cooldown", 15);

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/mace-recovery.c":1
    ]));

    addSpecification("command template", "kata taxing contact at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## a taxing mace contact "
        "at ##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":5,
            "range":2
        ])
    }));
    addSpecification("damage stamina points", ({
        ([
            "probability":100,
            "base damage":9,
            "range":3
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"perception",
            "formula":"additive",
            "rate":0.15
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
            "name":"wisdom",
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
            "type":"attribute",
            "name":"strength",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"skill",
            "name":"mace",
            "formula":"additive",
            "rate":0.03
        ])
    }));
}
