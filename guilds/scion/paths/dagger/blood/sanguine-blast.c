//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/sanguine-blast.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponSkill = "dagger";
    WeaponType = "dagger";
    ValidWeaponTypes = ({ "dagger", "short sword" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
