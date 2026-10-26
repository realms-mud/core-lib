//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Draw Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "Before steel clears its resting place, the cut already has a "
        "direction. Learn to join the turn of the wrist to that hidden "
        "line instead of correcting it after the draw.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":7
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/katana/quick-draw.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/katana/quick-draw.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Quick Draw":3,
        "Measured Cut":1,
        "Rising Cut":1,
        "Breath Cut":1,
        "Needle Thrust":1,
        "Silent Edge":2
    ]));
}
