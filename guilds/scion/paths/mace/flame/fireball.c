//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/flame/fireball.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "mace";
    WeaponSkill = "mace";
    ValidWeaponTypes = ({ "mace", "flail" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
