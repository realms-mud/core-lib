//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrath Smite");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master smite - the wrath smite. This is a powerful "
        "diagonal smiteing stroke dealt from the wrath guard and ending "
        "in a wechsel guard on the opposite side. When used to displace "
        "another smite, the impact and weapon binding will result in the smite "
        "ending in a hanging parry.");
    addSpecification("limited by", (["equipment":({ "staff" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 15 ]));

    addPrerequisite("/guilds/scion/paths/staff/forms/over-smite.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/staff/forms/wrath-guard.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/staff/forms/wechsel.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus staff", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
}
