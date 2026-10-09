//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sorcery Amplification");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research enhances all elven sorcery "
        " abilities through deeper understanding.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/mana-sight.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Starlight": 25, "Moonbeam": 25, "Moonfire": 25,
        "Eldritch Star": 25, "Celestial Lance": 25,
        "Ancient Power": 25, "Elder Star": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
