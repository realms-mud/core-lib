//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/ice/ice-javelin.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "dagger";
    WeaponSkill = "dagger";
    ValidWeaponTypes = ({ "dagger", "short sword" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
