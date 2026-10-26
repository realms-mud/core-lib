//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hook Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "Straight weapons teach the eye to expect a straight answer. "
        "Map the space behind that expectation, where the kama's "
        "inward edge can turn a harmless-looking reach into a cut.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
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
    addPrerequisite("/guilds/monk/kama/measured-hook.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/kama/measured-hook.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Measured Hook":3,
        "Sickle Check":1,
        "Breath Hook":1,
        "Reaping Cut":2,
        "Crescent Reap":2,
        "Sickle Recentering":1
    ]));
}
