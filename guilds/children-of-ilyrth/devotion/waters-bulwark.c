//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Water's Bulwark");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to strengthen their protective barrier, providing "
        "significant damage absorption and defense.");

    addSpecification("limited by", (["research active": ({
        "/guilds/children-of-ilyrth/devotion/root.c" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 29 ]));

    addPrerequisite("/guilds/children-of-ilyrth/devotion/waters-screen.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 5);
    addSpecification("bonus defense", 2);
}
