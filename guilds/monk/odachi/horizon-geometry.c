//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Horizon Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "Mark the broad stroke's beginning and its end in the dust. "
        "The lesson lies between them: keeping your center inside "
        "the circle while the edge travels its rim.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":13
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "student", "disciple", "adept", "senior disciple",
            "master candidate", "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/odachi/horizon-cut.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/odachi/horizon-cut.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Horizon Cut":3,
        "Committed Cut":1,
        "Weight Check":1,
        "Long Point":2,
        "Descending Arc":2,
        "Returning Arc":2,
        "Final Horizon":2
    ]));
}
