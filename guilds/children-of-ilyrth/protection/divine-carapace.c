//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Carapace");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with a "
        "divine carapace blessed by Ilryth herself. The caster's body is "
        "encased in an invisible armor of sacred water.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 63 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/oceanic-immortality.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 60);
    addSpecification("bonus defense", 10);
    addSpecification("bonus soak", 12);
    addSpecification("apply damage reflection", 25);

    addSpecification("affected research", ([
        "Tsunami Shield": 25,
        "Ilyryth's Sanctuary": 25,
        "Mantle of Ilyrth": 25
    ]));
    addSpecification("affected research type", "percentage");
}
