//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Restorative Breath");
    addSpecification("source", "monk");
    addSpecification("description",
        "The infirmary teaches a gentler use for a fighter's discipline. "
        "Follow the ache rather than fleeing it, carrying the breath "
        "into places the body has tightened against its own pain.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":36
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/centering-breath.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/centering-breath.c",
            "/guilds/monk/unarmed/returning-breath.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Centering Breath":3,
        "Returning Breath":3
    ]));
}
