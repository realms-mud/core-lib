//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sickle Distance");
    addSpecification("source", "monk");
    addSpecification("description",
        "A hook reaches differently from a straight blade. Measure "
        "the gap with your eyes until you can judge where the point "
        "passes and where the inner edge will finally close.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":8
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/root.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/hook-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("bonus perception", 1);
}
