//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendent Conduit");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of transcendent psychic projection, allowing mastery "
        "of the most powerful methods.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 40 ]));

    addPrerequisite("/guilds/oneiromancer/projection-methods/perfected-conduit.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Collective Resonance": 25,
        "Perfect Clarity": 25,
        "Absolute Conviction": 25,
        "Nightmare Echo": 20
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 4);
    addSpecification("bonus evocation", 3);
    addSpecification("bonus intelligence", 1);
}
