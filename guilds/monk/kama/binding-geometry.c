//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Binding Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "A hooked blade need not win a contest of strength. Study the "
        "angles that make an opponent lift, twist, and brace against "
        "their own weight whenever the sickle presses close.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"kama",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":14
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
    addPrerequisite("/guilds/monk/kama/binding-hook.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/kama/binding-hook.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Binding Hook":3,
        "Sickle Check":2,
        "Reaping Cut":1,
        "Sickle Point":1,
        "Quiet Hook":1
    ]));
}
