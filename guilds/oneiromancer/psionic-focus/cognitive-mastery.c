//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cognitive Mastery");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of exploiting cognitive weaknesses, enhancing attacks "
        "that target thought and reason.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 20 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/cognitive-fracture.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/overwhelming-presence.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Cognitive Fracture": 20,
        "Will Breaker": 20,
        "Sanity Erosion": 15,
        "Perception Warp": 15
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 3);
    addSpecification("bonus attack", 2);
}
