//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rake Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "The padded dummy is marked with seams narrower than "
        "your hand. Work along them until the clustered points "
        "can enter cleanly without wasting their force against the guard.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":3
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/measured-rake.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/claw/measured-rake.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Measured Rake":3,
        "Claw Check":1,
        "Breath Rake":1,
        "Crossing Rake":2,
        "Rising Talon":2,
        "Claw Recentering":1
    ]));
}
