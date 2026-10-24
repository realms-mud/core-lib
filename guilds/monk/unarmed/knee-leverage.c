//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Knee Leverage");
    addSpecification("source", "monk");
    addSpecification("description",
        "Understanding leverage adds three points to Disrupting Knee's "
        "stamina drain, two to Crushing Embrace's drain, and one to "
        "Measured Palm and Rising Heel.");

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
        "value":18
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
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
    addPrerequisite("/guilds/monk/unarmed/disrupting-knee.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/disrupting-knee.c",
            "/guilds/monk/unarmed/crushing-embrace.c",
            "/guilds/monk/unarmed/measured-palm.c",
            "/guilds/monk/unarmed/rising-heel.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Disrupting Knee":3,
        "Crushing Embrace":2,
        "Measured Palm":1,
        "Rising Heel":1
    ]));
}
