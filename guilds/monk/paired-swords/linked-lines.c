//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Linked Lines");
    addSpecification("source", "monk");
    addSpecification("description",
        "Two swords need not tell the same story. Learn how the "
        "short blade's watchful presence allows the long blade "
        "to speak with a clearer, more certain voice.");

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
        "value":3
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/paired-swords/linked-cut.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/paired-swords/linked-cut.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Linked Cut":3,
        "Companion Check":1,
        "Breath Shear":1,
        "Crossing Cut":2,
        "Alternating Cut":2,
        "Paired Recentering":1
    ]));
}
