//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pulse Mapping");
    addSpecification("source", "monk");
    addSpecification("description",
        "Listen at the wrist, the throat, and the hollow of the elbow. "
        "Each pulse tells a different part of the body's story; together "
        "they reveal where a wounded current needs guidance or interruption.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":62
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/meridian-strike.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/meridian-strike.c",
            "/guilds/monk/unarmed/returning-breath.c",
            "/guilds/monk/unarmed/sapping-palm.c",
            "/guilds/monk/unarmed/centering-breath.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Meridian Strike":3,
        "Returning Breath":3,
        "Sapping Palm":2,
        "Centering Breath":2
    ]));
}
