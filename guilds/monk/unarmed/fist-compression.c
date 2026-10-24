//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fist Compression");
    addSpecification("source", "monk");
    addSpecification("description",
        "Compressing a short striking arc adds three points to Hammer Fist "
        "and Empty Hand, two to Measured Palm and Driving Elbow, and one "
        "to Rising Heel and Crushing Embrace.");

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
        "value":32
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/hammer-fist.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/hammer-fist.c",
            "/guilds/monk/unarmed/empty-hand.c",
            "/guilds/monk/unarmed/measured-palm.c",
            "/guilds/monk/unarmed/driving-elbow.c",
            "/guilds/monk/unarmed/rising-heel.c",
            "/guilds/monk/unarmed/crushing-embrace.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Hammer Fist":3,
        "Empty Hand":3,
        "Measured Palm":2,
        "Driving Elbow":2,
        "Rising Heel":1,
        "Crushing Embrace":1
    ]));
}
