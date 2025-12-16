//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aegis of the Abyss");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to strengthen their protective barrier with the crushing "
        "weight of the ocean abyss.");

    addSpecification("limited by", (["research active": ({
        "/guilds/children-of-ilyrth/devotion/root.c" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 49 ]));

    addPrerequisite("/guilds/children-of-ilyrth/devotion/mantle-of-the-aegis.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 10);
    addSpecification("bonus defense", 5);
}
