//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Waters Purity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of water's inherent purity. The caster's cleansing magic "
        "becomes more effective at removing afflictions.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 7 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/cleansing-waters.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental water", 2);
    addSpecification("bonus resist poison", 3);

    addSpecification("affected research", ([
        "Cleansing Waters": 15
    ]));
    addSpecification("affected research type", "percentage");
}
