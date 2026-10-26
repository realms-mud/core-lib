//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heavy Leverage");
    addSpecification("source", "monk");
    addSpecification("description",
        "The long hilt is a lever, not a club to wave blindly. "
        "Learn to turn it against braced hands until the opponent "
        "must shoulder the weight you have already set in motion.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
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
    addPrerequisite("/guilds/monk/odachi/pommel-drive.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/odachi/pommel-drive.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Pommel Drive":3,
        "Committed Cut":1,
        "Weight Check":2,
        "Heavy Rebuke":2
    ]));
}
