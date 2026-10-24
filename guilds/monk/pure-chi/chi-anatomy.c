//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chi Anatomy");
    addSpecification("source", "monk");
    addSpecification("description",
        "Trace the channels that carry spell-point chi. This lesson opens "
        "precision projection and restorative work, strengthening these "
        "techniques as their channels become familiar.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":2
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
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/focused-pulse.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("related research", ({
        "/guilds/monk/pure-chi/needle-of-chi.c",
        "/guilds/monk/pure-chi/restorative-breath.c"
    }));

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Focused Pulse":3,
        "Needle of Chi":2,
        "Driving Wave":2,
        "Restorative Chi Breath":1,
        "Returning Current":1,
        "Heart Mending":1,
        "Piercing Intent":1,
        "Centered Release":1,
        "Renewal of Self":2,
        "Severing Current":1,
        "Silent Thunder":2
    ]));
}
