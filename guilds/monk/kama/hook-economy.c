//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hook Economy");
    addSpecification("source", "monk");
    addSpecification("description",
        "Clenching the haft only makes the curve fight your hand. "
        "Loosen the last fingers and let the sickle's balance carry "
        "the edge through the draw before closing your grip again.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":34
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/kama/hook-geometry.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/kama/hook-geometry.c" }));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Measured Hook":2
    ]));
}
