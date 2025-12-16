//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Veil of the Goddess");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to enhance their protective barrier with Ilyrth's divine "
        "grace, providing greater resistance to evil and magical attacks.");

    addSpecification("limited by", (["research active": ({
        "/guilds/children-of-ilyrth/devotion/root.c" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 35 ]));

    addPrerequisite("/guilds/children-of-ilyrth/devotion/might-of-ilyrth.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist evil", 5);
    addSpecification("bonus resist magical", 5);
}
