//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Surge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the mana surge technique. The "
        "spell sword learns to channel sudden bursts "
        "of raw magical energy through melee "
        "strikes, causing each blow to discharge a "
        "pulse of arcane force that overwhelms an "
        "opponent's defenses through sheer "
        "concentrated power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "arcane-vigor.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical enchantment", 4);
    addSpecification("bonus spell points", 20);
}
