//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Economy");
    addSpecification("source", "monk");
    addSpecification("description",
        "Learn the exact instant when a working has fulfilled its purpose. "
        "Close the circle without lingering, as a master lifts the "
        "brush before a finished stroke can blur.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":53
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
    addPrerequisite("/guilds/monk/pure-chi/channel-economy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Heart Mending":2,
        "Centered Release":2
    ]));
}
