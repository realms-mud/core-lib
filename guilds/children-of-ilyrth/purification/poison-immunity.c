//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Poison Immunity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with near "
        "immunity to poison. The caster's body has been so thoroughly "
        "purified that toxins have little effect.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 15 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/cure-poison.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist poison", 15);

    addSpecification("affected research", ([
        "Cure Poison": 25,
        "Cure Disease": 15
    ]));
    addSpecification("affected research type", "percentage");
}
