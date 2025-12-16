//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfected Conduit");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of perfecting psychic conduits, maximizing the power "
        "of advanced projection methods.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 30 ]));

    addPrerequisite("/guilds/oneiromancer/projection-methods/amplified-conduit.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Thoughtform Projection": 25,
        "Subliminal Insertion": 25,
        "Resonant Frequency": 20,
        "Overwhelming Presence": 20
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 3);
    addSpecification("bonus senses", 2);
    addSpecification("bonus spellcraft", 2);
}
