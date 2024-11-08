//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/ice/frost-tendrils.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "staff";
    WeaponSkill = "staff";

    addSpecification("limited by", (["equipment":({ "staff" })]));
}
