//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Affinity");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of drawing power from nightmare essence, enhancing "
        "attacks rooted in dream and fear.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 16 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/dream-fang.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/ruthless-precision.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Dream Fang": 20,
        "Cognitive Fracture": 15,
        "Sanity Erosion": 15,
        "Nightmare Fist": 10
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus evocation", 2);
    addSpecification("bonus wisdom", 1);
}
