//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Economical Refuge");
    addSpecification("source", "monk");
    addSpecification("description",
        "A shelter built against the wind needs no struggle to remain "
        "standing. So too can your stance support the shield, freeing "
        "your breath from the habit of fighting every impact.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":14
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
    addPrerequisite("/guilds/monk/mana-shield/guarded-breath.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Brace the Spirit":1,
        "Measured Renewal":2
    ]));
}
