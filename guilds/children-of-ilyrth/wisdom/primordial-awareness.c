//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Awareness");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "awareness from the primordial ocean. The caster taps into the "
        "ancient consciousness that existed before the world was formed.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 33 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/oracle-of-depths.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 7);
    addSpecification("bonus magical essence", 5);
    addSpecification("bonus ancient history", 5);
    addSpecification("bonus spellcraft", 3);
}
