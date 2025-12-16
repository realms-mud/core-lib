//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Amplified Conduit");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of amplifying psychic conduits, greatly improving "
        "intensity-based projection methods.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 22 ]));

    addPrerequisite("/guilds/oneiromancer/projection-methods/refined-conduit.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Psychic Touch": 20,
        "Focused Intent": 15,
        "Penetrating Thought": 15,
        "Amplified Sending": 20
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 2);
    addSpecification("bonus evocation", 2);
}
