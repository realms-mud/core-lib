//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pulse Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "Trace the invisible lines between the palm and its destination. "
        "Angles that seemed empty reveal where a current will spread, "
        "where it will gather, and where its edge will meet resistance.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":6
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/chi-anatomy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Needle of Chi":2,
        "Focused Pulse":1,
        "Driving Wave":1,
        "Piercing Intent":2,
        "Severing Current":2
    ]));
}
