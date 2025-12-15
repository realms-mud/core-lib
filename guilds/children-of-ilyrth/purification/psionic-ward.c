//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psionic Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "protection against mental attacks. The caster's mind is shielded "
        "by the calming depths of Ilyrth's waters.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 37 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/remove-curse.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist psionic", 10);
    addSpecification("bonus resist evil", 5);

    addSpecification("affected research", ([
        "Remove Curse": 20,
        "Absolute Purification": 15
    ]));
    addSpecification("affected research type", "percentage");
}
