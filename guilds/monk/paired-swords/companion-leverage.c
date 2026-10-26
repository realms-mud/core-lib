//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Companion Leverage");
    addSpecification("source", "monk");
    addSpecification("description",
        "A light touch from the wakizashi can make the longer "
        "blade feel impossibly heavy. Study where the hands "
        "share their burden and where the opponent must bear it.");

    addSpecification("limited by", ([
        "equipment":({
            ([
                "blueprint":"katana",
                "slot":"wielded primary"
            ]),
            ([
                "blueprint":"wakisashi",
                "slot":"wielded offhand"
            ])
        })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":6
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/paired-swords/companion-check.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/paired-swords/companion-check.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Companion Check":3,
        "Linked Cut":1,
        "Blade Bind":2,
        "Companion Thrust":1
    ]));
}
