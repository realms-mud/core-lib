//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Decisive Rhythm");
    addSpecification("source", "monk");
    addSpecification("description",
        "Victory must not draw the sword farther than the fight demands. "
        "Trace the finishing stroke back to its quiet center, ready "
        "for the opponent who has not yet fallen.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":64
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "master candidate",
        "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/decisive-angle.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/katana/decisive-angle.c" }));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Decisive Cut":4
    ]));
}
