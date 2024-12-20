//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/evocation/energy-storm.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "axe";
    WeaponSkill = "axe";
    ValidWeaponTypes = ({ "axe" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
