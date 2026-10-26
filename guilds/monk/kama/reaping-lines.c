//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reaping Lines");
    addSpecification("source", "monk");
    addSpecification("description",
        "Bundles of reeds mark the practice yard in uneven rows. "
        "Find the line through each without leaning past your feet, "
        "learning to bring a reaper's sure draw into the press of battle.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":30
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/reaping-cut.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/kama/reaping-cut.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Reaping Cut":3,
        "Measured Hook":1,
        "Binding Hook":1,
        "Crescent Reap":2,
        "Tiring Reap":2,
        "Returning Hook":2,
        "Final Reap":2
    ]));
}
