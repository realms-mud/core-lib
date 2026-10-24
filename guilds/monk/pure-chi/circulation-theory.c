//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Circulation Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "Study the return path of spent chi. This opens cleansing and "
        "stamina restoration without a new pool, adding three points of "
        "restorative strength to the techniques informed by this study.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
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
    addPrerequisite("/guilds/monk/pure-chi/restorative-breath.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Restorative Chi Breath":3,
        "Returning Current":3,
        "Heart Mending":3,
        "Renewal of Self":3
    ]));

    addSpecification("related research", ({
        "/guilds/monk/pure-chi/cleansing-breath.c",
        "/guilds/monk/pure-chi/returning-current.c"
    }));
}
