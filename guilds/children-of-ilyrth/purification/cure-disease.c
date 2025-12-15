//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cure Disease");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the cure disease spell. The caster calls upon Ilyrth's "
        "cleansing waters to purge disease from the target's body.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/disease-ward.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);

    addSpecification("remove modifier", "disease");

    addSpecification("cooldown", 45);
    addSpecification("event handler", "cureDiseaseEvent");
    addSpecification("command template", "cure disease [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ilryth's healing power as cleansing waters "
        "flood through ##TargetName##, washing away all disease.");
}
