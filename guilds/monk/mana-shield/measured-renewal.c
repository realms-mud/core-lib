//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Measured Renewal");
    addSpecification("source", "monk");
    addSpecification("description",
        "Follow a slow circle with your hands, drawing the shield's "
        "fluttering edge inward before opening it once more. The motion "
        "leaves your breath deep and your spirit freshly gathered.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":16
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/breath-conversion.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 60);

    addSpecification("command template", "chi measured renewal");
    addSpecification("use ability message",
        "##InitiatorName## draw##InitiatorReflexive## energy from a measured "
        "renewal of breath.");

    addSpecification("increase spell points", ({
        ([
            "probability":100,
            "base damage":12,
            "range":2
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type":"skill",
            "name":"meditation",
            "formula":"additive",
            "rate":0.12
        ]),
        ([
            "type":"skill",
            "name":"spellcraft",
            "formula":"additive",
            "rate":0.08
        ]),
        ([
            "type":"skill",
            "name":"healing",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"skill",
            "name":"concentration",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"wisdom",
            "formula":"additive",
            "rate":0.15
        ]),
        ([
            "type":"attribute",
            "name":"constitution",
            "formula":"additive",
            "rate":0.1
        ]),
        ([
            "type":"attribute",
            "name":"intelligence",
            "formula":"additive",
            "rate":0.06
        ]),
        ([
            "type":"research",
            "name":"Recovery Cycle",
            "research item":"/guilds/monk/mana-shield/recovery-cycle.c",
            "base value":1,
            "formula":"additive",
            "rate":3.0
        ]),
        ([
            "type":"research",
            "name":"Ward Anatomy",
            "research item":"/guilds/monk/mana-shield/ward-anatomy.c",
            "base value":1,
            "formula":"additive",
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Refuge Theory",
            "research item":"/guilds/monk/mana-shield/refuge-theory.c",
            "base value":1,
            "formula":"additive",
            "rate":2.0
        ])
    }));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/mana-shield/economical-refuge.c":2
    ]));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/renewing-rhythm.c":6
    ]));
}
