//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Meridian Lore");
    addSpecification("source", "monk");
    addSpecification("description",
        "Knowledge of concentration pathways adds three points to Sapping "
        "Palm and Meridian Strike, two to Returning Breath's healing, and "
        "one to Centering Breath's healing.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":40
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/sapping-palm.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/sapping-palm.c",
            "/guilds/monk/unarmed/meridian-strike.c",
            "/guilds/monk/unarmed/returning-breath.c",
            "/guilds/monk/unarmed/centering-breath.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Sapping Palm":3,
        "Meridian Strike":3,
        "Returning Breath":2,
        "Centering Breath":1
    ]));
}
