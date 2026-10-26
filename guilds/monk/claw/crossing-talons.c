//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crossing Talons");
    addSpecification("source", "monk");
    addSpecification("description",
        "Lay two reeds across one another to mark the guarding "
        "arm and the hidden road beyond it. The crossing lesson "
        "teaches your hand to find that road without wandering.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"tiger claws",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":31
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/claw/crossing-rake.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/claw/crossing-rake.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Crossing Rake":3,
        "Measured Rake":1,
        "Gripping Rake":1,
        "Rising Talon":2,
        "Tiring Rake":2,
        "Returning Rake":2,
        "Final Rake":2
    ]));
}
