//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Seas Memory");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with access "
        "to the sea's eternal memory. The caster can recall knowledge from "
        "the ocean's ancient depths, gaining wisdom of ages past.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 17 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/currents-truth.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus ancient history", 5);
    addSpecification("bonus theology", 4);
    addSpecification("bonus intelligence", 1);
}
