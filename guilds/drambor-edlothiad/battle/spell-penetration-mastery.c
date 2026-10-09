//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Penetration Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research further enhances spell "
        "penetration capabilities.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/spell-penetration.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arcane Bolt": 25, "Magic Missile": 25, "Chain Lightning": 25,
        "Force Blast": 25, "Arcane Barrage": 25, "War Magic": 25,
        "Meteor Storm": 25, "Arcane Cataclysm": 25, "Fireball": 25,
        "Ice Storm": 25, "Disintegrate": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
