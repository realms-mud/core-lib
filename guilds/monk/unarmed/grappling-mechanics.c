//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grappling Mechanics");
    addSpecification("source", "monk");
    addSpecification("description",
        "Efficient leverage adds three points to Crushing Embrace's stamina "
        "drain, two to Disrupting Knee's drain, and one to Driving Elbow "
        "and Hammer Fist. These techniques do not immobilize the opponent.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":48
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/crushing-embrace.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/crushing-embrace.c",
            "/guilds/monk/unarmed/disrupting-knee.c",
            "/guilds/monk/unarmed/driving-elbow.c",
            "/guilds/monk/unarmed/hammer-fist.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Crushing Embrace":3,
        "Disrupting Knee":2,
        "Driving Elbow":1,
        "Hammer Fist":1
    ]));
}
