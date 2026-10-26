//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quiet Intervals");
    addSpecification("source", "monk");
    addSpecification("description",
        "Do not chase the breath after it leaves you. Welcome the quiet "
        "interval in its place, and feel the returning current "
        "assemble itself without the disturbance of haste.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":41
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/circulation-theory.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/returning-current.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Restorative Chi Breath":4,
        "Returning Current":4
    ]));
}
