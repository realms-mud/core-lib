//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elbow Anatomy");
    addSpecification("source", "monk");
    addSpecification("description",
        "Anatomical placement strengthens palm, elbow, fist, knee, and "
        "meridian techniques. Driving Elbow gains three points; Empty Hand "
        "gains two; the other affected strikes gain one.");

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
        "value":9
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "initiate",
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/driving-elbow.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/driving-elbow.c",
            "/guilds/monk/unarmed/measured-palm.c",
            "/guilds/monk/unarmed/disrupting-knee.c",
            "/guilds/monk/unarmed/hammer-fist.c",
            "/guilds/monk/unarmed/sapping-palm.c",
            "/guilds/monk/unarmed/meridian-strike.c",
            "/guilds/monk/unarmed/empty-hand.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Driving Elbow":3,
        "Measured Palm":1,
        "Disrupting Knee":1,
        "Hammer Fist":1,
        "Sapping Palm":1,
        "Meridian Strike":1,
        "Empty Hand":2
    ]));
}
