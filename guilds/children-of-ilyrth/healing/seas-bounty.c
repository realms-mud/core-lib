//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Seas Bounty");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the sea's boundless bounty. Ilyrth's generosity flows "
        "through the caster, enhancing their ability to restore all aspects "
        "of vitality.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/natures-renewal.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 4);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus magical essence", 3);
    addSpecification("bonus heal hit points", 2);
    addSpecification("bonus heal spell points", 2);
    addSpecification("bonus heal stamina", 1);

    addSpecification("affected research", ([
        "Ocean Balm": 25,
        "Lifegiving Waters": 25,
        "Wellspring of Life": 20,
        "Ilryth's Blessing": 20,
        "Deluge of Healing": 15
    ]));
    addSpecification("affected research type", "percentage");
}
