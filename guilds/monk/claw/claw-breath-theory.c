//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Claw Breath Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "Read the tiny pause before a foe gathers their inward "
        "strength. A claw arriving in that pause can trouble "
        "concentration more deeply than a louder, less deliberate threat.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":19
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "student", "disciple", "adept", "senior disciple",
            "master candidate", "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/breath-rake.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/claw/breath-rake.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Breath Rake":3,
        "Quiet Rake":2,
        "Claw Recentering":2
    ]));
}
