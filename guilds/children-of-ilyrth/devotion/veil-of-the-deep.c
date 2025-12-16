//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Veil of the Deep");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to enhance their protective barrier with the cold depths "
        "of the ocean, providing additional resistance to fire.");

    addSpecification("limited by", (["research active": ({
        "/guilds/children-of-ilyrth/devotion/root.c" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 23 ]));

    addPrerequisite("/guilds/children-of-ilyrth/devotion/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus resist cold", 3);
}
