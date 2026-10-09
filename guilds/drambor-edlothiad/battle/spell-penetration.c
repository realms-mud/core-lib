//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Penetration");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research enhances the battlemage's "
        "ability to penetrate magical defenses with combat spells.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/spell-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
        ]));
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arcane Bolt": 25, "Magic Missile": 25, "Chain Lightning": 25,
        "Force Blast": 25, "Arcane Barrage": 25, "War Magic": 25,
        "Meteor Storm": 25, "Arcane Cataclysm": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
