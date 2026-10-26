//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pulse Cadence");
    addSpecification("source", "monk");
    addSpecification("description",
        "Hear the interval between the crash of a wave and its returning "
        "wash. Shape your projections to that cadence, allowing "
        "the next breath to rise naturally from the last.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":23
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
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
    addPrerequisite("/guilds/monk/pure-chi/pulse-geometry.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/needle-of-chi.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Driving Wave":2
    ]));
}
