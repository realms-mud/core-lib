//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hammer Poise");
    addSpecification("source", "monk");
    addSpecification("description",
        "Carry the hammer as a poised weight rather than a "
        "burden. The head waits above a settled stance, its "
        "promise of motion held without restless swaying.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("/guilds/monk/bludgeon/anvil-geometry.c", ([
        "type":"research"
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":60
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/braced-recovery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");

    addSpecification("bonus strength", 1);
    addSpecification("bonus defense", 5);
}
