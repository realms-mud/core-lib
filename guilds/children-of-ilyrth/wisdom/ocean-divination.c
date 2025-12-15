//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ocean Divination");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "art of reading the ocean's secrets. The caster learns to divine "
        "truths from the movement of water, gaining powerful insight.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 9 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/tidal-foresight.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 4);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus elemental water", 2);
}
