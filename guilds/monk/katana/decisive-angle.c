//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Decisive Angle");
    addSpecification("source", "monk");
    addSpecification("description",
        "The final opening rarely lies where the eye first seeks it. "
        "Read the angle hidden behind a faltering guard, and let the "
        "blade follow the truth rather than the invitation.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":58
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/decisive-cut.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/katana/decisive-cut.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Decisive Cut":3,
        "Measured Cut":2,
        "Descending Cut":2,
        "Breath Cut":2,
        "Silent Edge":3
    ]));
}
