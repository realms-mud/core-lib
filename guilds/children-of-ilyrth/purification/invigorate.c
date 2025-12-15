//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Invigorate");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the invigorate spell. The caster calls upon Ilryth's "
        "energizing currents to wash away fatigue, weakness, and sluggishness "
        "from the target.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 15 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/purifying-stream.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("remove modifier", ({ "slow", "enfeebled" }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "invigorateEvent");
    addSpecification("command template", "invigorate [##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon Ilryth's energizing currents as "
        "revitalizing waters surge through ##TargetName##, washing away "
        "weakness and fatigue.");
}
