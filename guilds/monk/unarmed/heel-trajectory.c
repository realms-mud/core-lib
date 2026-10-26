//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heel Trajectory");
    addSpecification("source", "monk");
    addSpecification("description",
        "Chalk arcs on the courtyard wall mark the path of the heel. "
        "Follow them until the hip opens cleanly and the standing foot "
        "can carry the whole rising curve without wavering.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":28
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/rising-heel.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/rising-heel.c",
            "/guilds/monk/unarmed/empty-hand.c",
            "/guilds/monk/unarmed/disrupting-knee.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Rising Heel":3,
        "Empty Hand":2,
        "Disrupting Knee":1
    ]));
}
