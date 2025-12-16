//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Mastery");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "mastery over the healing tides. The caster commands the ebb and "
        "flow of Ilyrth's restorative waters with greater precision and "
        "power.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/ocean-surge.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 4);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus elemental water", 3);
    addSpecification("bonus heal hit points", 2);
    addSpecification("bonus heal hit points rate", 1);

    addSpecification("affected research", ([
        "Soothing Touch": 25,
        "Healing Stream": 25,
        "Healing Rain": 25,
        "Wellspring of Life": 20,
        "Ilryth's Blessing": 20,
        "Deluge of Healing": 15
    ]));
    addSpecification("affected research type", "percentage");
}
