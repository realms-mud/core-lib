//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Strike Supremacy");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with supremacy in the spell strike "
        "art. Every blow landed carries the full "
        "weight of the spell sword's arcane "
        "knowledge behind it, transforming simple "
        "swordplay into a vehicle for delivering "
        "devastating magical payloads with each "
        "carefully aimed strike.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "legendary-spell-sword.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus magical enchantment", 5);
}
