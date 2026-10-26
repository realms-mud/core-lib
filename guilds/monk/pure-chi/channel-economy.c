//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Channel Economy");
    addSpecification("source", "monk");
    addSpecification("description",
        "Study the instant when a torrent leaves its channel. By closing "
        "the passage gently behind it, you keep the trailing current from "
        "scattering into useless sparks.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":35
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/measured-expenditure.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Driving Wave":2,
        "Piercing Intent":2
    ]));
}
