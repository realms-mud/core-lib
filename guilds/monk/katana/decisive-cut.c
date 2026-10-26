//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Decisive Cut");
    addSpecification("source", "monk");
    addSpecification("description",
        "All the small corrections of the duel fall away. You step "
        "through the opening with a cut that leaves neither doubt nor "
        "a wavering hand behind it.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":56
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/descending-lines.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 18);

    addSpecification("command template", "kata decisive cut at ##Target##");
    addSpecification("usage summary", "kata decisive cut at <target>");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## decisive cut against "
        "##TargetName##.");

    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "slash");
    addSpecification("damage hit points", ({
        ([
            "probability":100,
            "base damage":28,
            "range":5
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
            "name":"constitution",
            "formula":"additive",
            "rate":0.05
        ]),
        ([
            "type":"research",
            "name":"Descending Lines",
            "research item":"/guilds/monk/katana/descending-lines.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
        ]),
        ([
            "type":"research",
            "name":"Circular Mechanics",
            "research item":"/guilds/monk/katana/circular-mechanics.c",
            "formula":"additive",
            "base value":1,
            "rate":2.0
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
            "name":"decisive-angle",
            "research item":"/guilds/monk/katana/decisive-angle.c",
            "formula":"additive",
            "base value":1,
            "rate":3.0
        ])
    }));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/katana/decisive-rhythm.c":4
    ]));
}
