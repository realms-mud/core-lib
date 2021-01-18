//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/spirit/soul-shard.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "axe";
    WeaponSkill = "axe";
    ValidWeaponTypes = ({ "axe" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
