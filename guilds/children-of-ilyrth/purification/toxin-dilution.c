//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Toxin Dilution");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to dilute and neutralize toxins. The caster gains "
        "resistance to poison and enhanced ability to cure it.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 7 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/cleansing-waters.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist poison", 5);
    addSpecification("bonus herbalism", 2);

    addSpecification("affected research", ([
        "Cleansing Waters": 15,
        "Cure Poison": 10
    ]));
    addSpecification("affected research type", "percentage");
}
