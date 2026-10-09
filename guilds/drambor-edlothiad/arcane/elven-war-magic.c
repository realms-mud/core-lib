//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven War Magic");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of traditional elven "
        "war magic as practiced by the ancient "
        "Drambor. These techniques blend the fluid "
        "grace of elven swordplay with potent arcane "
        "augmentation, creating a fighting style that "
        "is as elegant as it is devastating.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "war-magic-infusion.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 35
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 4);
    addSpecification("bonus attack", 3);
}
