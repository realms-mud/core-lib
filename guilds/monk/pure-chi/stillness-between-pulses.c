//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stillness Between Pulses");
    addSpecification("source", "monk");
    addSpecification("description",
        "Allow each projection to end completely before you summon "
        "another. The brief silence between them becomes a clean "
        "page, free of the last gesture's unfinished intent.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":65
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/pulse-cadence.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Needle of Chi":1,
        "Driving Wave":2
    ]));
}
