//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/destruction.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponSkill = "dagger";
    WeaponType = "dagger";
    ValidWeaponTypes = ({ "dagger", "short sword" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
