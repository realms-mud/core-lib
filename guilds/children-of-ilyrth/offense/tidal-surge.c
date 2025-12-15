//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Surge");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the cleric's water-based offensive "
        "abilities.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 11 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/crashing-wave.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Water's Rebuke": 25,
        "Crashing Wave": 25,
        "Drowning Grasp": 25,
        "Ocean Fury": 25,
        "Wrath of the Deep": 25,
        "Churning Vortex": 25,
        "Ilryth's Tide": 25,
        "Primordial Flood": 25,
        "Divine Annihilation": 25
    ]));
    addSpecification("affected research type", "percentage");
}
