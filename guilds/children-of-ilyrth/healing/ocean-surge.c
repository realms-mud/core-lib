//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ocean Surge");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to channel the ocean's surging power. The caster's "
        "healing magic swells like a great wave, carrying increased "
        "restorative energy.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 17 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/healing-cascade.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 3);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus elemental water", 2);
    addSpecification("bonus spell points", 10);

    addSpecification("affected research", ([
        "Soothing Touch": 20,
        "Healing Stream": 20,
        "Healing Rain": 20,
        "Wellspring of Life": 15,
        "Ilryth's Blessing": 15
    ]));
    addSpecification("affected research type", "percentage");
}
