//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grip Discipline");
    addSpecification("source", "monk");
    addSpecification("description",
        "Hold the katana firmly enough to guide it, gently enough to "
        "hear its weight. The teacher's correction begins in the "
        "little fingers, not in the strength of the arms.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":2
    ]));
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/measured-cut.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("bonus hand and a half sword", 1);
}
