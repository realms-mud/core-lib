//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Commitment Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "An odachi does not forgive a decision made halfway through "
        "the stroke. Read the opening before the blade moves, and "
        "learn what it means to place your whole stance behind it.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
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
    addPrerequisite("/guilds/monk/odachi/committed-cut.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/odachi/committed-cut.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Committed Cut":3,
        "Pommel Drive":1,
        "Horizon Cut":2,
        "Breath Cleaver":1,
        "Descending Arc":2,
        "Longblade Recentering":1
    ]));
}
