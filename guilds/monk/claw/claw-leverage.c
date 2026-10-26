//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Claw Leverage");
    addSpecification("source", "monk");
    addSpecification("description",
        "Against a padded partner, learn where a short threat "
        "forces a long response. Shoulder, elbow, and hip can "
        "be made to labor even when the talons barely advance.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":6
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/claw-check.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/claw/claw-check.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Claw Check":3,
        "Measured Rake":1,
        "Gripping Rake":2,
        "Tiring Rake":2
    ]));
}
