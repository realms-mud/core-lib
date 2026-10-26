//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Circular Mechanics");
    addSpecification("source", "monk");
    addSpecification("description",
        "A circle drawn by the hands alone has no heart. Study how the "
        "turn begins beneath the feet and travels unbroken through the "
        "hips to the farthest inch of steel.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":42
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/drawn-circle.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/katana/drawn-circle.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Drawn Circle":3,
        "Quick Draw":2,
        "Guard Breaker":1,
        "Decisive Cut":2,
        "Silent Edge":2
    ]));
}
