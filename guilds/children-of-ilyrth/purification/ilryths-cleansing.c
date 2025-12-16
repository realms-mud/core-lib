//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilryths Cleansing");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "Ilyrth's own cleansing power. The caster's purification magic is "
        "blessed with divine potency.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 33 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/ocean-purge.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical essence", 5);
    addSpecification("bonus elemental water", 4);
    addSpecification("bonus resist evil", 5);

    addSpecification("affected research", ([
        "Cleansing Waters": 30,
        "Cure Poison": 25,
        "Cure Disease": 25,
        "Remove Paralysis": 25,
        "Ocean Purge": 20
    ]));
    addSpecification("affected research type", "percentage");
}
