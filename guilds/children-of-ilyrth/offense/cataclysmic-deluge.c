//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cataclysmic Deluge");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "knowledge that further enhances the cleric's water-based offensive "
        "abilities.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 51 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/primordial-flood.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Water's Rebuke": 25,
        "Crashing Wave": 25,
        "Drowning Grasp": 25,
        "Ocean Fury": 25,
        "Wrath of the Deep": 25,
        "Maelstrom": 25,
        "Tsunami": 25,
        "Primordial Flood": 25,
        "Divine Annihilation": 25
    ]));
    addSpecification("affected research type", "percentage");
}
