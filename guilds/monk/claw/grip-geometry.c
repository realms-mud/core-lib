//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grip Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "Map the bends that make a defending arm heavy. The "
        "claw frame need only threaten those angles to make "
        "the foe spend breath holding their own body against you.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":15
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "student", "disciple", "adept", "senior disciple",
            "master candidate", "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/gripping-rake.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/claw/gripping-rake.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Gripping Rake":3,
        "Claw Check":2,
        "Crossing Rake":1,
        "Talon Point":1,
        "Quiet Rake":1
    ]));
}
