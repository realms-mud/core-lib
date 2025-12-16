//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Overwhelming Presence");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of projecting an overwhelming psychic presence that "
        "enhances crushing and breaking attacks.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 14 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/ego-rend.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/penetrating-thought.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Thought Crush": 15,
        "Ego Rend": 15,
        "Memory Shatter": 15,
        "Will Breaker": 10
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 2);
    addSpecification("bonus intelligence", 1);
}
