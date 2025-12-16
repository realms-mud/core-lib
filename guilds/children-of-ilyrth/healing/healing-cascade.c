//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Healing Cascade");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to amplify their area healing magic. Like a cascade of "
        "waterfalls, the caster's group healing spells flow with greater "
        "abundance.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/healing-rain.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 3);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus heal hit points rate", 1);

    addSpecification("affected research", ([
        "Healing Rain": 20,
        "Lifegiving Waters": 15
    ]));
    addSpecification("affected research type", "percentage");
}
