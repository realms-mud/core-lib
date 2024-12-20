//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/ice/frost-tendrils.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "dagger";
    WeaponSkill = "dagger";

    addSpecification("limited by", (["equipment":({ "dagger", "short sword" })]));
}
