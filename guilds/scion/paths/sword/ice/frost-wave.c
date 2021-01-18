//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/ice/frost-wave.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "sword";
    WeaponSkill = "long sword";
    ValidWeaponTypes = ({ "long sword", "hand and a half sword",
        "two-handed sword" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
