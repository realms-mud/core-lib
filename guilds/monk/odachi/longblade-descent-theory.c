//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Longblade Descent Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "A falling sword can still wander. Study the moment the "
        "hips settle beneath the lifted hilt, giving the descending "
        "edge a purpose more exact than gravity alone.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":43
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/odachi/descending-arc.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/odachi/descending-arc.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Descending Arc":3,
        "Horizon Cut":1,
        "Long Point":1,
        "Returning Arc":2,
        "Final Horizon":2
    ]));
}
