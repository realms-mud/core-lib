//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Measured Rake");
    addSpecification("source", "monk");
    addSpecification("description",
        "Begin close enough to see the foe's breath catch. "
        "A short, deliberate extension of the hand carries the "
        "tiger-claw points through the opening before the shoulder follows.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":1
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/root.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 10);

    addSpecification("command template", "kata measured rake at ##Target##");
    addSpecification("usage summary", "kata measured rake at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## measured rake against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "thrust");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":10,
            "range":0
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
            "name":"dexterity",
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
            "type":"research",
            "name":"Rake Geometry",
            "research item":"/guilds/monk/claw/rake-geometry.c",
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
            "rate":0.05
        ]),
        ([
            "type":"attribute",
            "name":"strength",
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
            "name":"Claw Leverage",
            "research item":"/guilds/monk/claw/claw-leverage.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ]),
        ([
            "type":"research",
            "name":"Crossing Talons",
            "research item":"/guilds/monk/claw/crossing-talons.c",
            "formula":"additive",
            "base value":1,
            "rate":1.0
        ])
    }));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/claw/rake-economy.c":2
    ]));
}
