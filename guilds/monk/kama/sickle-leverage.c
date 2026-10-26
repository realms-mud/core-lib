//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sickle Leverage");
    addSpecification("source", "monk");
    addSpecification("description",
        "Spar with a weighted practice haft and watch which turns "
        "make your partner labor. A slight change of hook or elbow "
        "can ask more of their stance than a heavy shove ever could.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":6
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/sickle-check.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/kama/sickle-check.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Sickle Check":3,
        "Measured Hook":1,
        "Binding Hook":2,
        "Tiring Reap":2
    ]));
}
