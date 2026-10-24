//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bow Draw Economy");
    addSpecification("source", "monk");
    addSpecification("description",
        "Avoid wasted tension: reduces Measured Draw's stamina cost by two, "
        "without saving its arrow.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":22
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "disciple",
        "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/draw-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/archery/draw-geometry.c" }));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Measured Draw":2
    ]));
}
