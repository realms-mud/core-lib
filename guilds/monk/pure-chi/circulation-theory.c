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
        "No current truly ends where the eye loses it. Follow the breath "
        "back through the body's winding channels and discover how "
        "outward exertion may find its way home.");

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
