//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bow Leverage");
    addSpecification("source", "monk");
    addSpecification("description",
        "Trace the angles that force a defender to turn against "
        "their own balance. A small change at release can demand "
        "a much greater effort where the arrow arrives.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":7
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/archery/arresting-shot.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/archery/arresting-shot.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Arresting Shot":3,
        "Measured Draw":1,
        "Burdening Shot":1,
        "Descending Shot":1,
        "Exhausting Shot":1
    ]));
}
