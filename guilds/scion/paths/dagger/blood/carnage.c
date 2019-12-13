//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/guilds/scion/common/blood/carnage.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "dagger";
    WeaponSkill = "dagger";

    addSpecification("limited by", (["equipment":({
        "dagger", "short sword" })]));
}
