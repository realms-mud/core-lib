//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Point of Release");
    addSpecification("source", "monk");
    addSpecification("description",
        "Attend to the instant between holding and letting go. "
        "The fingers must open without command or hesitation, "
        "leaving the arrow's narrow course untouched.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"bow",
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
    addPrerequisite("/guilds/monk/archery/narrow-line-shot.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/archery/narrow-line-shot.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Narrow-Line Shot":3,
        "Measured Draw":2,
        "Breath-Piercing Shot":1,
        "Quieting Shot":1,
        "Final Draw":2
    ]));
}
