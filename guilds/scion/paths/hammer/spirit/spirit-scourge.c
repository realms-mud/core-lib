//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/spirit/spirit-scourge.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "hammer";
    WeaponSkill = "hammer";
    ValidWeaponTypes = ({ "hammer" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
