//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/enervating-barrier.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponSkill = "dagger";
    WeaponType = "dagger";

    addSpecification("limited by", (["equipment":({
        "dagger", "short sword" })]));
}
