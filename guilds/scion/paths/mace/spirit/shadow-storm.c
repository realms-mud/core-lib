//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/spirit/shadow-storm.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "mace";
    WeaponSkill = "mace";
    ValidWeaponTypes = ({ "mace", "flail" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
