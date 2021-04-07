//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/soul-shear.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponSkill = "dagger";
    WeaponType = "dagger";
    ValidWeaponTypes = ({ "dagger", "short sword" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
