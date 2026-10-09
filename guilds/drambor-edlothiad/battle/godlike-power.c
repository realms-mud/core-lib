//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Godlike Power");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents power rivaling "
        "that of the divine, the absolute peak of battle magic.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/legendary-battle-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 18);
    addSpecification("bonus magical essence", 15);
    addSpecification("bonus spell points", 125);
}
