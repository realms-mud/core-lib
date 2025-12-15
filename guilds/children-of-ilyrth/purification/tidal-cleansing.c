//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Cleansing");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "power of tidal cleansing. The caster's purification magic surges "
        "with increased potency.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 11 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/soothing-flow.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental water", 3);
    addSpecification("bonus divine essence", 2);

    addSpecification("affected research", ([
        "Cleansing Waters": 20,
        "Cure Poison": 15,
        "Cure Disease": 15
    ]));
    addSpecification("affected research type", "percentage");
}
