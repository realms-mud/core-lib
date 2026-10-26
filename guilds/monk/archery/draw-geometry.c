//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Draw Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "Trace a straight course from the drawn string through "
        "the arrow's point. The lesson lies in every small angle "
        "that can bend a faithful release away from its purpose.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
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
    addPrerequisite("/guilds/monk/archery/measured-draw.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/archery/measured-draw.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Measured Draw":3,
        "Crosswind Shot":1,
        "Narrow-Line Shot":1,
        "Final Draw":1
    ]));
}
