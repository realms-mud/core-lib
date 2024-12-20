//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/sanguine-blast.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "sword";
    WeaponSkill = "long sword";
    ValidWeaponTypes = ({ "long sword", "hand and a half sword",
        "two-handed sword" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
