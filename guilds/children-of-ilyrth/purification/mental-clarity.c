//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mental Clarity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "mental clarity of still waters. The caster's mind becomes as clear "
        "and impenetrable as the deepest ocean.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 45 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/psionic-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist psionic", 10);
    addSpecification("bonus wisdom", 2);

    addSpecification("affected research", ([
        "Remove Curse": 25,
        "Absolute Purification": 25
    ]));
    addSpecification("affected research type", "percentage");
}
