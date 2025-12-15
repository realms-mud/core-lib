//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Enlightenment");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "divine enlightenment from Ilyrth. The caster's mind transcends "
        "mortal limitations, achieving a state of perfect awareness.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 63 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/avatar-of-wisdom.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 12);
    addSpecification("bonus divine essence", 10);
    addSpecification("bonus wisdom", 3);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus spell points", 40);
}
